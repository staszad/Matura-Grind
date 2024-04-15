// Matura Grind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

bool zad591(long int number) {
    if (number % 2 == 0)
        return false;

    int liczbaCzynnikow = 0;
    for (int i = 3; i <= number; i += 2) {
        if (number % i == 0) {
            liczbaCzynnikow++;
            number /= i;
            while (number % i == 0)
                number /= i;
        }
    }
    if(liczbaCzynnikow == 3)
        return true;
    return false;
}

bool zad592(long int number) {
    long int reversed = 0;
    long int numberCopy = number;
    while (numberCopy) {
        reversed = reversed * 10 + numberCopy % 10;
        numberCopy /= 10;
    }
    
    long sum = number + reversed;
    long sumCopy = sum;
    long reversedSum = 0;
    while (sumCopy) {
        reversedSum = reversedSum * 10 + sumCopy % 10;
        sumCopy /= 10;
    }
    return (sum == reversedSum);
}

int zad593(long number) {
    int power = 0;
    int tmp = 1;
    do {
        while (number) {
            tmp *= number % 10;
            number /= 10;
        }
        number = tmp;
        tmp = 1;
        power++;
    } while (number > 9);
    return power;
}

bool zad801(int a, int b, int c) {
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (max == a)
        return (b * b + c * c == a * a);
    if (max == b)
        return (a * a + c * c == b * b);
    return (a * a + b * b == c * c);
}

bool zad802(int a, int b, int c) {
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (max == a)
        return (b + c > a);
    if (max == b)
        return (a + c > b);
    return (a + b > c);
}

bool zad721(std::string text1, std::string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    if (len2 > len1) {
        int tmp = len1;
        len1 = len2;
        len2 = tmp;
    }

    return (len1 / len2 >= 3);
}

int zad722(std::string text1, std::string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    if (len1 == len2)
        return 0;

    int i;
    for (i = 0; (i < len1 && i < len2); i++) {
        if (text1[i] != text2[i]){
            return 0;
        }
    }
    
    if (len1 > len2)
        return 1;
    else
        return 2;
}

int zad723(std::string text1, std::string text2) {
    int len1 = text1.length();
    int len2 = text2.length();

    int i;
    for (i = 1; (i <= len1 && i <= len2); i++) {
        if (text1[len1 - i] != text2[len2 - i])
            return i - 1;
    }
    return i - 1;
}

int main()
{
    std::cout << "Hello World!\n";

    //ZADANIE 59.1
    std::ifstream in;
    in.open("data/liczby59.txt");
    std::vector<long int> numbers;
    long int tmp;
    while (in >> tmp)
        numbers.push_back(tmp);
    
    //int result591 = 0;  
    //for (int i = 0; i < numbers.size(); i++) {
    //    if (zad591(numbers[i]))
    //        result591++;
    //}
    //std::cout << "zad 59.1: " << result591 << "\n";

    ////ZADANIE 59.2
    //int result592 = 0;
    //for (int i = 0; i < numbers.size(); i++) {
    //    if (zad592(numbers[i]))
    //        result592++;
    //}
    //std::cout << "zad 59.2: " << result592 << "\n";

    ////ZADANIE 59.3
    //int result593[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    //for (int i = 0; i < numbers.size(); i++) {
    //    int power = zad593(numbers[i]);
    //    if (power <= 8)
    //        result593[power-1]++;
    //    
    //}
    //std::cout << "zad 59.3: ";
    //for (int i = 0; i < 8; i++) {
    //    std::cout << i + 1 << ": " << result593[i] << ", ";
    //}
    //std::cout << std::endl;
    in.close();

    //ZADANIE 80
    in.open("data/dane_trojkaty.txt");
    std::vector<int> trSides;
    while (in >> tmp)
        trSides.push_back(tmp);
    in.close();

    ////ZADANIE 80.1
    //std::cout << "zad 80.1: ";
    //for (int i = 0; i < trSides.size() - 2; i++) {
    //    if (zad801(trSides[i], trSides[i + 1], trSides[i + 2]))
    //        std::cout << trSides[i] << " " << trSides[i+1] << " " << trSides[i+2] << "; ";
    //}
    //std::cout << std::endl;

    ////ZADANIE 80.2
    ////sorting vector desc
    //bool sorted = false;
    //while (!sorted) {
    //    sorted = true;
    //    for (int i = 0; i < trSides.size() - 1; i++) {
    //        if (trSides[i + 1] > trSides[i]) {
    //            sorted = false;
    //            tmp = trSides[i + 1];
    //            trSides[i + 1] = trSides[i];
    //            trSides[i] = tmp;
    //        }
    //    }
    //}

    //for (int i = 0; i < trSides.size() - 2; i++) {
    //    if (zad802(trSides[i], trSides[i + 1], trSides[i + 2])) {
    //        std::cout << "zad 80.2: " << trSides[i] + trSides[i + 1] + trSides[i + 2] << "\n";
    //        break;
    //    }
    //}

    ////ZADANIE 80.3
    //int numOfTriangles = 0;
    //for (int i = 0; i < trSides.size() - 2; i++) {
    //    for (int j = i + 1; j < trSides.size() - 2; j++) {
    //        for (int k = j + 1; k < trSides.size(); k++) {
    //            if (zad802(trSides[i], trSides[j], trSides[k]))
    //                numOfTriangles++;
    //        }
    //    }
    //}
    //std::cout << "zad 80.3: " << numOfTriangles << "\n";

    //ZADANIE 72
    in.open("data/napisy.txt");
    std::vector<std::string> texts;
    std::string tmpText;
    while (in >> tmpText) {
        texts.push_back(tmpText);
    }
    in.close();

    //ZADANIE 72.1
    int result72 = 0;
    std::string firstPair = "";
    for (int i = 0; i < texts.size(); i += 2) {
        if (zad721(texts[i], texts[i+1])) {
            result72++;
            if (firstPair == "")
                firstPair += texts[i] + " " + texts[i+1];
        }
    }
    std::cout << "zad 72.1: " << result72 << ", pierwsza taka para: " << firstPair << "\n";

    //ZADANIE 72.2
    std::cout << "\nzad 72.2:\n";
    for (int i = 0; i < texts.size(); i+=2) {
        if (zad722(texts[i], texts[i+1]) == 2) {
            std::cout << texts[i] << " " << texts[i + 1] << " ";
            for (int j = texts[i].length(); j < texts[i+1].length(); j++)
                std::cout << texts[i+1][j];
            std::cout << std::endl;
        }
        if (zad722(texts[i], texts[i + 1]) == 1) {
            std::cout << texts[i] << " " << texts[i + 1] << " ";
            for (int j = texts[i+1].length(); j < texts[i].length(); j++)
                std::cout << texts[i][j];
            std::cout << std::endl;
        }
    }

    //ZADANIE 72.3
    std::vector<std::string> sameEnds;
    int maxEndLen = 1;
    for (int i = 0; i < texts.size(); i += 2) {
        int endLen = zad723(texts[i], texts[i + 1]);
        if (endLen > maxEndLen) {
            maxEndLen = endLen;
            sameEnds.clear();
            sameEnds.push_back(texts[i] + " " + texts[i + 1]);
        } else if (endLen == maxEndLen)
            sameEnds.push_back(texts[i] + " " + texts[i + 1]);
    }

    std::cout << "\nzad72.3: " << maxEndLen << std::endl;
    for (int i = 0; i < sameEnds.size(); i++) {
        std::cout << sameEnds[i] << std::endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
