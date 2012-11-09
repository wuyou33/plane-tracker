/********************************************************************************
** Form generated from reading UI file 'ui.ui'
**
** Created: Thu Nov 8 18:32:33 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *controls;
    QVBoxLayout *panTiltLayout;
    QLabel *panTiltLabel;
    QSlider *panSlider;
    QSlider *tiltSlider;
    QLabel *amplificationLabel;
    QSlider *amplificationSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *toggleVideoButton;
    QPushButton *toggleGPSButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QString::fromUtf8("UI"));
        UI->resize(446, 373);
        centralWidget = new QWidget(UI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        controls = new QHBoxLayout();
        controls->setSpacing(6);
        controls->setObjectName(QString::fromUtf8("controls"));
        panTiltLayout = new QVBoxLayout();
        panTiltLayout->setSpacing(6);
        panTiltLayout->setObjectName(QString::fromUtf8("panTiltLayout"));
        panTiltLabel = new QLabel(centralWidget);
        panTiltLabel->setObjectName(QString::fromUtf8("panTiltLabel"));

        panTiltLayout->addWidget(panTiltLabel);

        panSlider = new QSlider(centralWidget);
        panSlider->setObjectName(QString::fromUtf8("panSlider"));
        panSlider->setMinimum(-90);
        panSlider->setMaximum(90);
        panSlider->setValue(0);
        panSlider->setOrientation(Qt::Horizontal);

        panTiltLayout->addWidget(panSlider);


        controls->addLayout(panTiltLayout);

        tiltSlider = new QSlider(centralWidget);
        tiltSlider->setObjectName(QString::fromUtf8("tiltSlider"));
        tiltSlider->setMinimum(-45);
        tiltSlider->setMaximum(90);
        tiltSlider->setValue(0);
        tiltSlider->setOrientation(Qt::Vertical);

        controls->addWidget(tiltSlider);

        amplificationLabel = new QLabel(centralWidget);
        amplificationLabel->setObjectName(QString::fromUtf8("amplificationLabel"));

        controls->addWidget(amplificationLabel);

        amplificationSlider = new QSlider(centralWidget);
        amplificationSlider->setObjectName(QString::fromUtf8("amplificationSlider"));
        amplificationSlider->setMinimum(-10);
        amplificationSlider->setMaximum(10);
        amplificationSlider->setSingleStep(2);
        amplificationSlider->setOrientation(Qt::Vertical);

        controls->addWidget(amplificationSlider);


        verticalLayout->addLayout(controls);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toggleVideoButton = new QPushButton(centralWidget);
        toggleVideoButton->setObjectName(QString::fromUtf8("toggleVideoButton"));
        toggleVideoButton->setMinimumSize(QSize(0, 100));
        toggleVideoButton->setCheckable(true);

        horizontalLayout->addWidget(toggleVideoButton);

        toggleGPSButton = new QPushButton(centralWidget);
        toggleGPSButton->setObjectName(QString::fromUtf8("toggleGPSButton"));
        toggleGPSButton->setMinimumSize(QSize(0, 100));
        toggleGPSButton->setCheckable(true);

        horizontalLayout->addWidget(toggleGPSButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        UI->setCentralWidget(centralWidget);
        amplificationLabel->raise();
        amplificationLabel->raise();
        menuBar = new QMenuBar(UI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 446, 22));
        UI->setMenuBar(menuBar);
        statusBar = new QStatusBar(UI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UI->setStatusBar(statusBar);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QMainWindow *UI)
    {
        UI->setWindowTitle(QApplication::translate("UI", "UI", 0, QApplication::UnicodeUTF8));
        panTiltLabel->setText(QApplication::translate("UI", "Tracker Pan/Tilt", 0, QApplication::UnicodeUTF8));
        amplificationLabel->setText(QApplication::translate("UI", "Tracker Amplification", 0, QApplication::UnicodeUTF8));
        toggleVideoButton->setText(QApplication::translate("UI", "Disable Video", 0, QApplication::UnicodeUTF8));
        toggleGPSButton->setText(QApplication::translate("UI", "Disable GPS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H