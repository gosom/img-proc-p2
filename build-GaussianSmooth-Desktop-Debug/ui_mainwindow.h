/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Image;
    QAction *actionProcess_Image;
    QAction *actionSet_kernel_size;
    QAction *actionGather_stats;
    QAction *actionWrite_Kernel;
    QAction *actionBlur_method;
    QAction *actionWrap;
    QAction *actionRecursive_Blur;
    QAction *actionBenchmarks;
    QAction *actionAnamorphosis;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollAreaImage;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollAreaBlur;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(994, 585);
        MainWindow->setDocumentMode(false);
        actionLoad_Image = new QAction(MainWindow);
        actionLoad_Image->setObjectName(QString::fromUtf8("actionLoad_Image"));
        actionProcess_Image = new QAction(MainWindow);
        actionProcess_Image->setObjectName(QString::fromUtf8("actionProcess_Image"));
        actionProcess_Image->setEnabled(false);
        actionSet_kernel_size = new QAction(MainWindow);
        actionSet_kernel_size->setObjectName(QString::fromUtf8("actionSet_kernel_size"));
        actionSet_kernel_size->setEnabled(true);
        actionGather_stats = new QAction(MainWindow);
        actionGather_stats->setObjectName(QString::fromUtf8("actionGather_stats"));
        actionWrite_Kernel = new QAction(MainWindow);
        actionWrite_Kernel->setObjectName(QString::fromUtf8("actionWrite_Kernel"));
        actionBlur_method = new QAction(MainWindow);
        actionBlur_method->setObjectName(QString::fromUtf8("actionBlur_method"));
        actionWrap = new QAction(MainWindow);
        actionWrap->setObjectName(QString::fromUtf8("actionWrap"));
        actionRecursive_Blur = new QAction(MainWindow);
        actionRecursive_Blur->setObjectName(QString::fromUtf8("actionRecursive_Blur"));
        actionBenchmarks = new QAction(MainWindow);
        actionBenchmarks->setObjectName(QString::fromUtf8("actionBenchmarks"));
        actionAnamorphosis = new QAction(MainWindow);
        actionAnamorphosis->setObjectName(QString::fromUtf8("actionAnamorphosis"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollAreaImage = new QScrollArea(centralWidget);
        scrollAreaImage->setObjectName(QString::fromUtf8("scrollAreaImage"));
        scrollAreaImage->setWidgetResizable(true);
        scrollAreaImage->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 481, 489));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollAreaImage->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_3->addWidget(scrollAreaImage);

        scrollAreaBlur = new QScrollArea(centralWidget);
        scrollAreaBlur->setObjectName(QString::fromUtf8("scrollAreaBlur"));
        scrollAreaBlur->setWidgetResizable(true);
        scrollAreaBlur->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 481, 489));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollAreaBlur->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollAreaBlur);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 994, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Image);
        menuFile->addAction(actionProcess_Image);
        toolBar->addAction(actionLoad_Image);
        toolBar->addAction(actionSet_kernel_size);
        toolBar->addAction(actionBlur_method);
        toolBar->addSeparator();
        toolBar->addAction(actionProcess_Image);
        toolBar->addAction(actionGather_stats);
        toolBar->addAction(actionWrite_Kernel);
        toolBar->addAction(actionWrap);
        toolBar->addAction(actionRecursive_Blur);
        toolBar->addAction(actionBenchmarks);
        toolBar->addAction(actionAnamorphosis);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gaussian Blur", 0, QApplication::UnicodeUTF8));
        actionLoad_Image->setText(QApplication::translate("MainWindow", "Load Image", 0, QApplication::UnicodeUTF8));
        actionProcess_Image->setText(QApplication::translate("MainWindow", "Process Image", 0, QApplication::UnicodeUTF8));
        actionSet_kernel_size->setText(QApplication::translate("MainWindow", "Kernel size", 0, QApplication::UnicodeUTF8));
        actionGather_stats->setText(QApplication::translate("MainWindow", "Gather stats", 0, QApplication::UnicodeUTF8));
        actionWrite_Kernel->setText(QApplication::translate("MainWindow", "Write Kernel", 0, QApplication::UnicodeUTF8));
        actionBlur_method->setText(QApplication::translate("MainWindow", "blur method", 0, QApplication::UnicodeUTF8));
        actionWrap->setText(QApplication::translate("MainWindow", "wrap", 0, QApplication::UnicodeUTF8));
        actionRecursive_Blur->setText(QApplication::translate("MainWindow", "recursive Blur", 0, QApplication::UnicodeUTF8));
        actionBenchmarks->setText(QApplication::translate("MainWindow", "Benchmarks", 0, QApplication::UnicodeUTF8));
        actionAnamorphosis->setText(QApplication::translate("MainWindow", "Anamorphosis", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
