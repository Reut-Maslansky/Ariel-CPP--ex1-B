#include "snowman.hpp"
#include <string>
#include <array>

using namespace std;
const int base_number = 10; 
const int ind_hat =1, ind_nose = 2, ind_left_eye = 3, ind_right_eye = 4,
ind_left_hand = 5, ind_right_hand = 6, ind_torso = 7, ind_base = 8;
const int length_snowman=8;

namespace ariel
{
    bool goodLengthNum(long num);
    string H(int num); //hat
    string N(int num); //nose
    string L_R(int num); //eyes
    string X(int num); //left arm
    string Y(int num); //right arm
    string T(int num); //torso
    string B(int num); //base
    string snowman(long number)
    {
        if (!goodLengthNum(number))
        {
            throw out_of_range("bad length of number");
        }

        array<string, length_snowman> snowman;

        //looping over the number and sending each digit to the according function
        for (int i = length_snowman; i > 0; i--)
        {
            switch (i)
            {
            case ind_hat:
                snowman.at(i - 1) = H((int)number % base_number);
                break;
            case ind_nose:
                snowman.at(i - 1) = N((int)number % base_number);
                break;
            case ind_left_eye:
            case ind_right_eye:
                snowman.at(i - 1) = L_R((int)number % base_number);
                break;
            case ind_left_hand:
                snowman.at(i - 1) = X((int)number % base_number);
                break;
            case ind_right_hand:
                snowman.at(i - 1) = Y((int)number % base_number);
                break;
            case ind_torso:
                snowman.at(i - 1) = T((int)number % base_number);
                break;
            case ind_base:
                snowman.at(i - 1) = B((int)number % base_number);
                break;
            default:
                break;
            }

            number /= base_number;
        }

        // two arms up
        if (snowman.at(ind_left_hand - 1) == string("\\") && snowman.at(ind_right_hand - 1) == string("/"))
        {
            return snowman.at(ind_hat - 1) + "\n\\(" + snowman.at(ind_left_eye - 1) + snowman.at(ind_nose - 1) + snowman.at(ind_right_eye - 1) + ")/" + "\n (" + snowman.at(ind_torso - 1) + ") \n" + " (" + snowman.at(ind_base - 1) + ") ";
        }
        // left arm up, right arm down
        if (snowman.at(ind_left_hand - 1) == string("\\"))
        {
            return snowman.at(ind_hat - 1) + "\n\\(" + snowman.at(ind_left_eye - 1) + snowman.at(ind_nose - 1) + snowman.at(ind_right_eye - 1) + ") " + "\n (" + snowman.at(ind_torso - 1) + ")" + snowman.at(ind_right_hand - 1) + "\n" + " (" + snowman.at(ind_base - 1) + ") ";
        }
        //right arm up, left arm down
        if (snowman.at(ind_right_hand - 1) == string("/"))
        {
            return snowman.at(ind_hat - 1) + "\n" + " (" + snowman.at(ind_left_eye - 1) + snowman.at(ind_nose - 1) + snowman.at(ind_right_eye - 1) + ")/" + "\n" + snowman.at(ind_left_hand - 1) + "(" + snowman.at(ind_torso - 1) + ") \n" + " (" + snowman.at(ind_base - 1) + ") ";
        }
        //two arms down
        return snowman.at(ind_hat - 1) + "\n" + " (" + snowman.at(ind_left_eye - 1) + snowman.at(ind_nose - 1) + snowman.at(ind_right_eye - 1) + ") " + "\n" + snowman.at(ind_left_hand - 1) + "(" + snowman.at(ind_torso - 1) + ")" + snowman.at(ind_right_hand - 1) + "\n" + " (" + snowman.at(ind_base - 1) + ") ";
    }

    //check if the number on the correct length
    bool goodLengthNum(long num)
    {
        int count = 0;
        while (num > 0)
        {
            num /= base_number;
            count++;
        }
        return (count == length_snowman);
    }
    string H(int num)
    {
        switch (num)
        {
        case 1:
            return "       \n _===_ ";
        case 2:
            return "  ___  \n ..... ";
        case 3:
            return "   _   \n  /_\\  ";
        case 4:
            return "  ___  \n (_*_) ";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string N(int num)
    {
        switch (num)
        {
        case 1:
            return ",";
        case 2:
            return ".";
        case 3:
            return "_";
        case 4:
            return " ";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string L_R(int num)
    {
        switch (num)
        {
        case 1:
            return ".";
        case 2:
            return "o";
        case 3:
            return "O";
        case 4:
            return "-";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string X(int num)
    {
        switch (num)
        {
        case 1:
            return "<";
        case 2:
            return "\\";
        case 3:
            return "/";
        case 4:
            return " ";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string Y(int num)
    {
        switch (num)
        {
        case 1:
            return ">";
        case 2:
            return "/";
        case 3:
            return "\\";
        case 4:
            return " ";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string T(int num)
    {
        switch (num)
        {
        case 1:
            return " : ";
        case 2:
            return "] [";
        case 3:
            return "> <";
        case 4:
            return "   ";
        default:
            throw out_of_range("illegal digits");
        }
    }
    string B(int num)
    {
        switch (num)
        {
        case 1:
            return " : ";
        case 2:
            return "\" \"";
        case 3:
            return "___";
        case 4:
            return "   ";
        default:
            throw out_of_range("illegal digits");
        }
    }
}