#include "sentenceprocessor.h"
#include <QStringList>

/*Functions Implementation*/

//getting the no. of words in the sentence

int SentenceProcessor::getWordNumber(QString sentence){
    return sentence.split(" ").size();
}

//getting the no. of vowels in the sentence

int SentenceProcessor::getVowelNumber(QString sentence){
    int cVowels = 0;
    cVowels += sentence.count('a', Qt::CaseInsensitive);
    cVowels += sentence.count('e', Qt::CaseInsensitive);
    cVowels += sentence.count('i', Qt::CaseInsensitive);
    cVowels += sentence.count('o', Qt::CaseInsensitive);
    cVowels += sentence.count('u', Qt::CaseInsensitive);

    return cVowels;
}

//returns true if the sentence is reversible
bool SentenceProcessor::isReversible(QString sentence){
    int boolval = QString::compare(sentence, wordsReversed(sentence), Qt::CaseInsensitive);

    if (boolval == 0)
        return true;
    else
        return false;
}

//Reverses the sentence inputted by the user

QString SentenceProcessor::wordsReversed(QString sentence){
    QStringList temp = sentence.split(" ");
    QStringList reversed;

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        reversed.append(temp.at(i));
    }

    return reversed.join(" ");
}

//checks if sentence starts with a capital letter and ends with fullstops
//if not it makes the first letter/char uppercase and adds a fullstop at the end of sentence
QString SentenceProcessor::formatSentence(QString sentence){
    sentence.trimmed();
    sentence.replace(0, 1, sentence.at(0).toUpper());

    if (sentence.at(sentence.size()-1) != '.')
        sentence.append(".");

    return sentence;
}

