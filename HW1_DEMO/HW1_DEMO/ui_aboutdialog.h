/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(449, 320);
        textBrowser = new QTextBrowser(AboutDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 411, 271));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "About *.64 Image Viewer", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'PMingLiU'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#008000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#008000;\">This is a</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;"
                        "\">demonstration</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">program</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">to</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">open a</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">*.64</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">image</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">and</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">show</span><span style=\" font-size:10pt; color:#c0c0c0;\""
                        "> </span><span style=\" font-size:10pt; color:#008000;\">its</span><span style=\" font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-size:10pt; color:#008000;\">histogram</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Ta-Te</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Lin<"
                        "/span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt; color:#008000;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt; color:#008000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Department</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">of</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; "
                        "color:#008000;\">Biomechatronics</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Engineering</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">National</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Taiwan</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">University</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt;\"><br /></p>\n"
""
                        "<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">Version:</span><span style=\" font-family:'Courier New'; font-size:10pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New'; font-size:10pt; color:#008000;\">1.1</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
