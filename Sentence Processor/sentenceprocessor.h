#ifndef SENTENCEPROCESSOR_H
#define SENTENCEPROCESSOR_H

#include <QDialog>

class SentenceProcessor : public QDialog
{
    Q_OBJECT

public:
    static int getWordNumber(QString sentence);
    static int getVowelNumber(QString sentence);
    static bool isReversible(QString sentence);
    static QString wordsReversed(QString sentence);
    static QString formatSentence(QString sentence);

};

#endif // SENTENCEPROCESSOR_H
