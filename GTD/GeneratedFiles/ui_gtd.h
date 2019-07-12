/********************************************************************************
** Form generated from reading UI file 'gtd.ui'
**
** Created: Wed 17. Feb 23:39:35 2016
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GTD_H
#define UI_GTD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GTDClass
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QTableWidget *Tabla;
    QPushButton *Nuevo;
    QPushButton *Eliminar;
    QFrame *Formulario;
    QLabel *label_9;
    QLineEdit *Nombre;
    QComboBox *Pack;
    QPushButton *Aceptar;
    QPushButton *Cancelar;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *Lentillas;
    QLabel *label_16;
    QPushButton *Fecha_Entrada;
    QLabel *label_15;
    QLineEdit *Observaciones;
    QLineEdit *Busqueda;
    QLabel *label_11;
    QListWidget *Lista_Busqueda;
    QFrame *F_Calendario;
    QCalendarWidget *Calendario;

    void setupUi(QMainWindow *GTDClass)
    {
        if (GTDClass->objectName().isEmpty())
            GTDClass->setObjectName(QString::fromUtf8("GTDClass"));
        GTDClass->resize(1068, 562);
        GTDClass->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(GTDClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 1051, 541));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(125, 125, 125);\n"
"border: 5px solid rgb(95,95, 95);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Tabla = new QTableWidget(frame);
        if (Tabla->columnCount() < 6)
            Tabla->setColumnCount(6);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        Tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        Tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        Tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        Tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        Tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        Tabla->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        Tabla->setObjectName(QString::fromUtf8("Tabla"));
        Tabla->setGeometry(QRect(10, 10, 801, 521));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Tabla->sizePolicy().hasHeightForWidth());
        Tabla->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        Tabla->setFont(font1);
        Tabla->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"Border:0px;"));
        Tabla->setAutoScrollMargin(16);
        Tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Tabla->setTabKeyNavigation(false);
        Tabla->setProperty("showDropIndicator", QVariant(false));
        Tabla->setDragDropOverwriteMode(false);
        Tabla->setSelectionMode(QAbstractItemView::NoSelection);
        Tabla->horizontalHeader()->setHighlightSections(false);
        Tabla->horizontalHeader()->setMinimumSectionSize(100);
        Tabla->verticalHeader()->setVisible(false);
        Tabla->verticalHeader()->setDefaultSectionSize(30);
        Tabla->verticalHeader()->setMinimumSectionSize(30);
        Nuevo = new QPushButton(frame);
        Nuevo->setObjectName(QString::fromUtf8("Nuevo"));
        Nuevo->setGeometry(QRect(820, 30, 121, 51));
        Nuevo->setFont(font1);
        Nuevo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"border: 3px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy: -0.3,\n"
"radius: 1.35, stop: 0 rgba(21, 230,226,255), stop: 1 rgba(21, 230,226, 100));\n"
"\n"
"min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: rgb(21, 230, 255);\n"
"\n"
" }\n"
"\n"
"QPushButton:pressed{\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy:-0.3,\n"
"radius: 1.3, stop: 0 rgba(21,230,226, 100), stop: 1 rgba(21, 230,226,255));\n"
"}\n"
"\n"
""));
        Eliminar = new QPushButton(frame);
        Eliminar->setObjectName(QString::fromUtf8("Eliminar"));
        Eliminar->setGeometry(QRect(820, 100, 121, 51));
        Eliminar->setFont(font1);
        Eliminar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"border: 3px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy: -0.3,\n"
"radius: 1.35, stop: 0 rgba(21, 230,226,255), stop: 1 rgba(21, 230,226, 100));\n"
"\n"
"min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: rgb(21, 230, 255);\n"
"\n"
" }\n"
"\n"
"QPushButton:pressed{\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy:-0.3,\n"
"radius: 1.3, stop: 0 rgba(21,230,226, 100), stop: 1 rgba(21, 230,226,255));\n"
"}\n"
"\n"
""));
        Formulario = new QFrame(frame);
        Formulario->setObjectName(QString::fromUtf8("Formulario"));
        Formulario->setGeometry(QRect(240, 120, 351, 351));
        Formulario->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 180, 200);"));
        Formulario->setFrameShape(QFrame::StyledPanel);
        Formulario->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(Formulario);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 81, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        Nombre = new QLineEdit(Formulario);
        Nombre->setObjectName(QString::fromUtf8("Nombre"));
        Nombre->setGeometry(QRect(150, 15, 181, 21));
        QFont font3;
        font3.setPointSize(10);
        Nombre->setFont(font3);
        Nombre->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 2px solid grey;\n"
"background-color: rgb(255, 255, 255);"));
        Pack = new QComboBox(Formulario);
        Pack->setObjectName(QString::fromUtf8("Pack"));
        Pack->setGeometry(QRect(150, 260, 181, 22));
        Pack->setFont(font3);
        Pack->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid grey;"));
        Aceptar = new QPushButton(Formulario);
        Aceptar->setObjectName(QString::fromUtf8("Aceptar"));
        Aceptar->setGeometry(QRect(40, 310, 84, 23));
        Aceptar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy: -0.3,\n"
"radius: 1.35, stop: 0 rgba(21, 230,226,255), stop: 1 rgba(21, 230,226, 100));\n"
"\n"
"min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: rgb(21, 230, 255);\n"
"\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy:-0.3,\n"
"radius: 1.3, stop: 0 rgba(21,230,226, 100), stop: 1 rgba(21, 230,226,255));\n"
"}\n"
"\n"
"\n"
""));
        Cancelar = new QPushButton(Formulario);
        Cancelar->setObjectName(QString::fromUtf8("Cancelar"));
        Cancelar->setGeometry(QRect(220, 310, 86, 23));
        Cancelar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy: -0.3,\n"
"radius: 1.35, stop: 0 rgba(21, 230,226,255), stop: 1 rgba(21, 230,226, 100));\n"
"\n"
"min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"     background-color: rgb(21, 230, 255);\n"
"\n"
" }\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy:-0.3,\n"
"radius: 1.3, stop: 0 rgba(21,230,226, 100), stop: 1 rgba(21, 230,226,255));\n"
"}\n"
"\n"
"\n"
""));
        label_13 = new QLabel(Formulario);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 55, 101, 16));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        label_14 = new QLabel(Formulario);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 260, 101, 16));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        Lentillas = new QLineEdit(Formulario);
        Lentillas->setObjectName(QString::fromUtf8("Lentillas"));
        Lentillas->setGeometry(QRect(150, 50, 181, 21));
        Lentillas->setFont(font3);
        Lentillas->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 2px solid grey;\n"
"background-color: rgb(255, 255, 255);"));
        label_16 = new QLabel(Formulario);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 225, 121, 16));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        Fecha_Entrada = new QPushButton(Formulario);
        Fecha_Entrada->setObjectName(QString::fromUtf8("Fecha_Entrada"));
        Fecha_Entrada->setGeometry(QRect(150, 220, 181, 23));
        Fecha_Entrada->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: black;\n"
"border: 2px solid #555;\n"
"border-radius: 0px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.4, cy: -0.3,\n"
"fx: 0.4, fy: -0.3,\n"
"radius: 1.35, stop: 0 rgba(255, 255,255,255), stop: 1 rgba(255, 255,255, 255));\n"
"\n"
"min-width: 70px;\n"
"}\n"
""));
        label_15 = new QLabel(Formulario);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 95, 101, 16));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        Observaciones = new QLineEdit(Formulario);
        Observaciones->setObjectName(QString::fromUtf8("Observaciones"));
        Observaciones->setGeometry(QRect(150, 90, 181, 21));
        Observaciones->setFont(font3);
        Observaciones->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 2px solid grey;\n"
"background-color: rgb(255, 255, 255);"));
        Busqueda = new QLineEdit(frame);
        Busqueda->setObjectName(QString::fromUtf8("Busqueda"));
        Busqueda->setGeometry(QRect(820, 190, 151, 21));
        Busqueda->setFont(font3);
        Busqueda->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 2px solid grey;\n"
"background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(820, 170, 81, 16));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border: 0px;"));
        Lista_Busqueda = new QListWidget(frame);
        Lista_Busqueda->setObjectName(QString::fromUtf8("Lista_Busqueda"));
        Lista_Busqueda->setGeometry(QRect(820, 220, 221, 311));
        Lista_Busqueda->setFont(font1);
        Lista_Busqueda->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        F_Calendario = new QFrame(centralWidget);
        F_Calendario->setObjectName(QString::fromUtf8("F_Calendario"));
        F_Calendario->setGeometry(QRect(290, 170, 271, 221));
        F_Calendario->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        F_Calendario->setFrameShape(QFrame::StyledPanel);
        F_Calendario->setFrameShadow(QFrame::Raised);
        Calendario = new QCalendarWidget(F_Calendario);
        Calendario->setObjectName(QString::fromUtf8("Calendario"));
        Calendario->setGeometry(QRect(10, 20, 256, 171));
        Calendario->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        GTDClass->setCentralWidget(centralWidget);

        retranslateUi(GTDClass);

        QMetaObject::connectSlotsByName(GTDClass);
    } // setupUi

    void retranslateUi(QMainWindow *GTDClass)
    {
        GTDClass->setWindowTitle(QApplication::translate("GTDClass", "GTD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = Tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GTDClass", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = Tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GTDClass", "Lentillas", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = Tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GTDClass", "Observaciones", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = Tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GTDClass", "Venta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = Tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GTDClass", "Expiracion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = Tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GTDClass", "Restante", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Nuevo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Nuevo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Nuevo->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Nuevo->setText(QApplication::translate("GTDClass", "Nuevo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Eliminar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Eliminar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Eliminar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        Eliminar->setText(QApplication::translate("GTDClass", "Eliminar", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("GTDClass", "Nombre:", 0, QApplication::UnicodeUTF8));
        Pack->clear();
        Pack->insertItems(0, QStringList()
         << QApplication::translate("GTDClass", "1 mes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "2 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "3 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "4 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "5 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "6 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "7 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "8 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "9 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "10 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "11 meses", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GTDClass", "12 meses", 0, QApplication::UnicodeUTF8)
        );
        Aceptar->setText(QApplication::translate("GTDClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Cancelar->setText(QApplication::translate("GTDClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("GTDClass", "Tipo lentillas:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("GTDClass", "Pack:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("GTDClass", "Fecha entregada:", 0, QApplication::UnicodeUTF8));
        Fecha_Entrada->setText(QString());
        label_15->setText(QApplication::translate("GTDClass", "Observaciones:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("GTDClass", "Busqueda:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GTDClass: public Ui_GTDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GTD_H
