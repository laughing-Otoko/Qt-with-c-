#include "sentenceprocessor.h"
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>

/*Functions for getting data from user*/
QStringList getSentence(){
    QStringList inputs;
    bool yes;
    /*choice made by user*/
    QString Syes;

    inputs.append(QInputDialog::getText(0, "Type your Sentence", "Type in your sentence (minimum of 2 words): ", QLineEdit::Normal, QString(" "), &yes));
    Syes = yes? "Yes" : "No";
    inputs.append(Syes);
    return inputs;

}

bool ValiadateInput(QString input){
    if(input.size() == 0)
        return false;
    if (input.split(" ").size() < 2) //Must at least have two words
    {
        QMessageBox::information(0,"Incorrect Input", "Type at least 2 words");
        return false;
    }
    return true;
}

QString generateOutput(QString input){
    QString output = QString("Your Input: %1\n").arg(input);
    output.append(QString("No. of Words: %1\n").arg(SentenceProcessor::getWordNumber(input)));
    output.append(QString("No. of Vowels: %1\n").arg(SentenceProcessor::getVowelNumber(input)));
    output.append(QString("Words reversed: %1\n").arg(SentenceProcessor::wordsReversed(input)));

    bool boolval2 = SentenceProcessor::isReversible(input);
    QString YorN = boolval2? "True" : "False" ;

    output.append(QString("Sentence is reversible: %1\n").arg(YorN));
    output.append(QString("formatted Sentence: %1\n").arg(SentenceProcessor::formatSentence(input)));

    return output;
}

void displayOut(QString output){
    QMessageBox::information(0, "Output", output);
}

int tryAgain()
{
    return QMessageBox::question(0, "New Sentence?", "Do you want to type in another sentence?", QMessageBox::Yes | QMessageBox::No);

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int response = 0;
    QStringList input;

    //prompt user for sentence

    do{
        do{
            input = getSentence();
            if (input.at(1) == "No")
                exit(0);
        }while(!ValiadateInput(input.at(0)));

        QString output  = generateOutput(input.at(0));
        displayOut(output);
        response = tryAgain();
    } while (response == QMessageBox::Yes);

    return EXIT_SUCCESS;
}
