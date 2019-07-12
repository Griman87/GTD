#include "gtd.h"
#include <windows.h>
#include <time.h>
#include <qtimer>
#include "sql.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>

int numero_elementos = 0;
bool ok = false;
QSqlDatabase db;
int dias_a_restar = 0;
int modificar = 0;
int fila_seleccionada = 0;
int dia_nuevo;
int mes_nuevo;
int anio_nuevo;
QString DNI_modificar;

GTD::GTD(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	SYSTEMTIME tiempo;
	SYSTEMTIME tiempo2;
	QString a1;
	
	QTableWidgetItem * elemento2 = new QTableWidgetItem;
	QTableWidgetItem * elemento3 = new QTableWidgetItem;
	QTableWidgetItem * elemento4 = new QTableWidgetItem;
	QTableWidgetItem * elemento5 = new QTableWidgetItem;
	QTableWidgetItem * elemento6 = new QTableWidgetItem;

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("TIME.s3db");
	ok = db.open();
	int dia;
	int mes;
	int anio;
	int dia_actual;
	int mes_actual;
	int anio_actual;
	int i;
	int contador_dias = 0;

	QSqlQuery query;

	GetSystemTime(&tiempo);

	//Se crea la base de datos si aun no ha sido creadada. Si no hay ningun dato es que no hay nada en la lista
	a1 = "create table Tiempo (Fecha varchar(30), DIA int, MES int, ANIO int)";
	ok = query.exec(a1);

	a1 = "create table Paciente (Nombre varchar(50),  Lentillas varchar(50), Observaciones varchar(200), Entrada varchar(50), Caducidad varchar(50))";
	ok = query.exec(a1);

	ui.setupUi(this);


	if (ok == true)
	{
		a1 = "INSERT INTO Tiempo (Fecha)""VALUES ('Fec')";
		ok = query.exec(a1);
	}
	else
	{
		ok = query.exec("SELECT DIA FROM Tiempo");
		query.next();
		dia = query.value(0).toInt();
		ok = query.exec("SELECT MES FROM Tiempo");
		query.next();
		mes = query.value(0).toInt();
		ok = query.exec("SELECT ANIO FROM Tiempo");
		query.next();
		anio = query.value(0).toInt();
	}
	

	//Se borra la base de datos para guardar el nuevo fichero
	a1 = "DELETE FROM Tiempo";
	ok = query.exec(a1);

	dia_actual = tiempo.wDay;
	mes_actual = tiempo.wMonth;
	anio_actual = tiempo.wYear;
	

	

	numero_elementos = 0;
	ok = query.exec("SELECT Nombre FROM Paciente");
	while(query.next())
	{
		ui.Tabla->insertRow(ui.Tabla->rowCount());
		numero_elementos++;
		QTableWidgetItem * elemento2 = new QTableWidgetItem;
		elemento2->setText(query.value(0).toString());
		ui.Tabla->setItem(numero_elementos-1,0,elemento2);


			QLinearGradient gradient9(0, 0, 0, 30);
			gradient9.setColorAt(0, QColor::fromRgb(116,255, 251,170));
			gradient9.setColorAt(1, QColor::fromRgb(130, 130, 130,170));
			QBrush brush9(gradient9);
			elemento2->setBackground(brush9);
		
	}


	numero_elementos = 0;
	ok = query.exec("SELECT Lentillas FROM Paciente");
	while(query.next())
	{
		numero_elementos++;
		QTableWidgetItem * elemento4 = new QTableWidgetItem;
		elemento4->setText(query.value(0).toString());
		ui.Tabla->setItem(numero_elementos-1,1,elemento4);


			QLinearGradient gradient9(0, 0, 0, 30);
			gradient9.setColorAt(0, QColor::fromRgb(116,255, 251,170));
			gradient9.setColorAt(1, QColor::fromRgb(130, 130, 130,170));
			QBrush brush9(gradient9);
			elemento4->setBackground(brush9);
		
	}

	numero_elementos = 0;
	ok = query.exec("SELECT Observaciones FROM Paciente");
	while(query.next())
	{
		numero_elementos++;
		QTableWidgetItem * elemento5 = new QTableWidgetItem;
		elemento5->setText(query.value(0).toString());
		ui.Tabla->setItem(numero_elementos-1,2,elemento5);


			QLinearGradient gradient9(0, 0, 0, 30);
			gradient9.setColorAt(0, QColor::fromRgb(116,255, 251,170));
			gradient9.setColorAt(1, QColor::fromRgb(130, 130, 130,170));
			QBrush brush9(gradient9);
			elemento5->setBackground(brush9);
		
	}

	numero_elementos = 0;
	ok = query.exec("SELECT Entrada FROM Paciente");
	while(query.next())
	{
		numero_elementos++;
		QTableWidgetItem * elemento6 = new QTableWidgetItem;
		elemento6->setText(query.value(0).toString());
		ui.Tabla->setItem(numero_elementos-1,3,elemento6);

	}

	numero_elementos = 0;
	ok = query.exec("SELECT Caducidad FROM Paciente");
	while(query.next())
	{
		numero_elementos++;
		QTableWidgetItem * elemento7 = new QTableWidgetItem;
		elemento7->setText(query.value(0).toString());
		ui.Tabla->setItem(numero_elementos-1,4,elemento7);

	}
	
	ui.Formulario->setVisible(false);
	QTimer * timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(cambio()));
	timer->start(250);

	ui.F_Calendario->setVisible(false);
}

GTD::~GTD()
{

}

void GTD::on_Nuevo_clicked()
{
	ui.Nombre->setText("");
	ui.Observaciones->setText("");
	ui.Lentillas->setText("");
	ui.Formulario->setVisible(true);
	modificar = 0;
}

void GTD::on_Cancelar_clicked()
{
	ui.Formulario->setVisible(false);
}

void GTD::on_Aceptar_clicked()
{
	QSqlQuery query;
	QString a1;
	int mes = 0;
	int anio = 0;
	QString fecha_entrega;
	QByteArray c1iliar;
	char * c1;

	QTableWidgetItem * elemento = new QTableWidgetItem;
	QTableWidgetItem * elemento2 = new QTableWidgetItem;
	QTableWidgetItem * elemento3 = new QTableWidgetItem;
	QTableWidgetItem * elemento4 = new QTableWidgetItem;
	QTableWidgetItem * elemento5 = new QTableWidgetItem;
	QTableWidgetItem * elemento6 = new QTableWidgetItem;
	QTableWidgetItem * elemento7 = new QTableWidgetItem;

	c1iliar = ui.Fecha_Entrada->text().toLocal8Bit();
	c1 = c1iliar.data();

	dia_nuevo = atoi(c1);
	c1 = strchr(c1,'/');
	c1 = c1+1;
	mes_nuevo = atoi(c1);
	c1 = strchr(c1,'/');
	c1 = c1+1;
	anio_nuevo = atoi(c1);
	
	if (modificar == 0)
	{
		ui.Tabla->insertRow(ui.Tabla->rowCount());
		numero_elementos++;
	
		QLinearGradient gradient9(0, 0, 0, 30);
		gradient9.setColorAt(0, QColor::fromRgb(116,255, 251,170));
		gradient9.setColorAt(1, QColor::fromRgb(130, 130, 130,170));
		QBrush brush9(gradient9);
		elemento->setBackground(brush9);
		elemento2->setBackground(brush9);
		elemento3->setBackground(brush9);
		elemento4->setBackground(brush9);
		elemento5->setBackground(brush9);

		elemento->setText(ui.Nombre->text());
		ui.Tabla->setItem(numero_elementos-1,0,elemento);

		elemento2->setText(ui.Lentillas->text());
		ui.Tabla->setItem(numero_elementos-1,1,elemento2);

		elemento3->setText(ui.Observaciones->text());
		ui.Tabla->setItem(numero_elementos-1,2,elemento3);

		elemento6->setText(ui.Fecha_Entrada->text());
		ui.Tabla->setItem(numero_elementos-1,3,elemento6);

		ui.Fecha_Entrada->setText(QString::number(dia_nuevo)+"/"+QString::number(mes_nuevo)+"/"+QString::number(anio_nuevo));

		switch (ui.Pack->currentIndex())
		{
			case 0:
				{
					mes = mes_nuevo+1;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 1:
				{
					mes = mes_nuevo+2;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}

					if (dia_nuevo > 28)
						dia_nuevo = 28;
				};break;

			case 2:
				{
					mes = mes_nuevo+3;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 3:
				{
					mes = mes_nuevo+4;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 4:
				{
					mes = mes_nuevo+5;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 5:
				{
					mes = mes_nuevo+6;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 6:
				{
					mes = mes_nuevo+7;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 7:
				{
					mes = mes_nuevo+8;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 8:
				{
					mes = mes_nuevo+9;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 9:
				{
					mes = mes_nuevo+10;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 10:
				{
					mes = mes_nuevo+11;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 11:
				{
					mes = mes_nuevo+12;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;
		}
		if ((mes == 2) && (dia_nuevo > 28))
			dia_nuevo = 28;
		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
		{
			if (dia_nuevo > 30)
				dia_nuevo = 30;
		}

		elemento7->setText(QString::number(dia_nuevo)+"/"+QString::number(mes)+"/"+QString::number(anio));
		ui.Tabla->setItem(numero_elementos-1,4,elemento7);

		a1 = "INSERT INTO Paciente (Nombre, Lentillas, Observaciones, Entrada, Caducidad)""VALUES ('"+elemento->text()+"','"+elemento2->text()+"','"+elemento3->text()+"','"+elemento6->text()+"','"+elemento7->text()+"')";
		ok = query.exec(a1);

		QMessageBox msgBox;
		msgBox.setText("Cliente añadido correctamente");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setWindowTitle("Añadir");
		int ret = msgBox.exec();
	}
	else
	{
		QSqlQuery query;
		QString a1;
		QTableWidgetItem * elemento01 = new QTableWidgetItem;
		QTableWidgetItem * elemento02 = new QTableWidgetItem;
		QTableWidgetItem * elemento03 = new QTableWidgetItem;
		QTableWidgetItem * elemento04 = new QTableWidgetItem;
		QTableWidgetItem * elemento05 = new QTableWidgetItem;
		QTableWidgetItem * elemento06 = new QTableWidgetItem;

		elemento01 = ui.Tabla->item(fila_seleccionada,0);
		elemento02 = ui.Tabla->item(fila_seleccionada,1);
		elemento03 = ui.Tabla->item(fila_seleccionada,2);
		elemento04 = ui.Tabla->item(fila_seleccionada,3);
		elemento05 = ui.Tabla->item(fila_seleccionada,4);
		elemento06 = ui.Tabla->item(fila_seleccionada,5);

		a1 = "DELETE FROM Paciente WHERE  NOMBRE = '"+elemento01->text()+"'";
		ok = query.exec(a1);
		
		numero_elementos--;

		ui.Tabla->removeRow(fila_seleccionada);

		ui.Tabla->insertRow(ui.Tabla->rowCount());
		numero_elementos++;
	
		QLinearGradient gradient9(0, 0, 0, 30);
		gradient9.setColorAt(0, QColor::fromRgb(116,255, 251,170));
		gradient9.setColorAt(1, QColor::fromRgb(130, 130, 130,170));
		QBrush brush9(gradient9);
		elemento->setBackground(brush9);
		elemento2->setBackground(brush9);
		elemento3->setBackground(brush9);
		elemento4->setBackground(brush9);
		elemento5->setBackground(brush9);

		elemento->setText(ui.Nombre->text());
		ui.Tabla->setItem(numero_elementos-1,0,elemento);

		elemento2->setText(ui.Lentillas->text());
		ui.Tabla->setItem(numero_elementos-1,1,elemento2);

		elemento3->setText(ui.Observaciones->text());
		ui.Tabla->setItem(numero_elementos-1,2,elemento3);

		elemento6->setText(ui.Fecha_Entrada->text());
		ui.Tabla->setItem(numero_elementos-1,3,elemento6);

		//ui.Fecha_Entrada->setText(QString::number(dia_nuevo)+"/"+QString::number(mes_nuevo)+"/"+QString::number(anio_nuevo));

		switch (ui.Pack->currentIndex())
		{
			case 0:
				{
					mes = mes_nuevo+1;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 1:
				{
					mes = mes_nuevo+2;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 28)
						dia_nuevo = 28;
				};break;

			case 2:
				{
					mes = mes_nuevo+3;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 3:
				{
					mes = mes_nuevo+4;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 4:
				{
					mes = mes_nuevo+5;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 5:
				{
					mes = mes_nuevo+6;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 6:
				{
					mes = mes_nuevo+7;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 7:
				{
					mes = mes_nuevo+8;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 8:
				{
					mes = mes_nuevo+9;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 9:
				{
					mes = mes_nuevo+10;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;

			case 10:
				{
					mes = mes_nuevo+11;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
					if (dia_nuevo > 30)
						dia_nuevo = 30;
				};break;

			case 11:
				{
					mes = mes_nuevo+12;
					if (mes > 12)
					{
						mes = mes - 12;
						anio = anio_nuevo + 1;
					}
					else
					{
						anio = anio_nuevo;
					}
				};break;
		}
		if ((mes == 2) && (dia_nuevo > 28))
			dia_nuevo = 28;
		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
		{
			if (dia_nuevo > 30)
				dia_nuevo = 30;
		}

		elemento7->setText(QString::number(dia_nuevo)+"/"+QString::number(mes)+"/"+QString::number(anio));
		ui.Tabla->setItem(numero_elementos-1,4,elemento7);

		a1 = "INSERT INTO Paciente (Nombre, Lentillas, Observaciones, Entrada, Caducidad)""VALUES ('"+elemento->text()+"','"+elemento2->text()+"','"+elemento3->text()+"','"+elemento6->text()+"','"+elemento7->text()+"')";
		ok = query.exec(a1);

		QMessageBox msgBox;
		msgBox.setText("Cliente modificado correctamente");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setWindowTitle("Modificar");
		int ret = msgBox.exec();
	}

	modificar = 0;
	ui.Formulario->setVisible(false);
}

void GTD::on_Tabla_cellClicked(int row, int column)
{
	fila_seleccionada = row;
}

void GTD::on_Tabla_cellDoubleClicked(int row, int column)
{
	
	int a;
	char * pch;
	char * expresion;
	QByteArray c1iliar;
	QTableWidgetItem * elemento = new QTableWidgetItem;
	QTableWidgetItem * elemento2 = new QTableWidgetItem;
	QTableWidgetItem * elemento3 = new QTableWidgetItem;
	QTableWidgetItem * elemento4 = new QTableWidgetItem;
	QTableWidgetItem * elemento5 = new QTableWidgetItem;
	QTableWidgetItem * elemento6 = new QTableWidgetItem;

	ui.Formulario->setVisible(true);
	
	elemento = ui.Tabla->item(row,0);
	elemento2 = ui.Tabla->item(row,1);
	elemento3 = ui.Tabla->item(row,2);
	elemento4 = ui.Tabla->item(row,3);



	ui.Nombre->setText(elemento->text());
	ui.Lentillas->setText(elemento2->text());
	ui.Observaciones->setText(elemento3->text());
	ui.Fecha_Entrada->setText(elemento4->text());

	DNI_modificar = elemento3->text();
	
	modificar = 1;
	fila_seleccionada = row;
}

void GTD::on_Eliminar_clicked()
{
	QSqlQuery query;
	QString a1;
	QTableWidgetItem * elemento = new QTableWidgetItem;
	QTableWidgetItem * elemento2 = new QTableWidgetItem;
	QTableWidgetItem * elemento3 = new QTableWidgetItem;
	QTableWidgetItem * elemento4 = new QTableWidgetItem;
	QTableWidgetItem * elemento5 = new QTableWidgetItem;
	QTableWidgetItem * elemento6 = new QTableWidgetItem;

	if (numero_elementos > 0)
	{
		elemento = ui.Tabla->item(fila_seleccionada,0);
		elemento2 = ui.Tabla->item(fila_seleccionada,1);
		elemento3 = ui.Tabla->item(fila_seleccionada,2);
		elemento4 = ui.Tabla->item(fila_seleccionada,3);
		elemento5 = ui.Tabla->item(fila_seleccionada,4);

		QMessageBox msgBox;
		msgBox.setText("¿Desea eliminar al cliente de la lista?");
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		msgBox.setIcon(QMessageBox::Question);
		msgBox.setWindowTitle("Eliminar");
		int ret = msgBox.exec();

		if (ret == QMessageBox::Yes)
		{
			a1 = "DELETE FROM Paciente WHERE NOMBRE = '"+elemento->text()+"'";
			ok = query.exec(a1);
		
			numero_elementos--;
		
			ui.Tabla->removeRow(fila_seleccionada);

			QMessageBox msgBox;
			msgBox.setText("Cliente eliminado de la lista correctamente");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.setIcon(QMessageBox::Information);
			msgBox.setWindowTitle("Eliminar");
			int ret = msgBox.exec();
		}
	}
}

void GTD::on_Fecha_Entrada_clicked()
{
	ui.F_Calendario->setVisible(true);
}

void GTD::on_Calendario_selectionChanged()
{
	QTableWidgetItem * elemento = new QTableWidgetItem;
	
	QDate fecha;
	ui.F_Calendario->setVisible(false);

	fecha = ui.Calendario->selectedDate();

	dia_nuevo = fecha.day();
	mes_nuevo = fecha.month();
	anio_nuevo = fecha.year();
	
	ui.Fecha_Entrada->setText(QString::number(dia_nuevo)+"/"+QString::number(mes_nuevo)+"/"+QString::number(anio_nuevo));
}

void GTD::cambio()
{
	SYSTEMTIME tiempo;
	SYSTEMTIME tiempo2;
	int dias;
	int dia;
	int mes;
	int anio;
	char * aux = (char*)malloc(100*sizeof(char));
	char * pch;
	char * c1;
	QByteArray c1iliar;
	struct tm fec;
	struct tm fec2;
	time_t hora;
	time_t hora2;
	time_t hora3;
	int dias_restantes = 0;
	int i;
	int j;
	QDate actual;
	QDate expira;

	QTableWidgetItem * elemento = new QTableWidgetItem;
	QTableWidgetItem * caduca = new QTableWidgetItem;

	GetSystemTime(&tiempo);

	for (i = 0; i<numero_elementos;i++)
	{
		caduca = ui.Tabla->item(i,4);

		if (caduca != NULL)
		{
			c1iliar = caduca->text().toLocal8Bit();
			c1 = c1iliar.data();

			dia = atoi(c1);

			c1 = strchr(c1,'/');
			c1++;
/*
			if (dia > 10)
			{
				c1[0] = c1[3];
				c1[1] = c1[4];
			}
			else
			{
				c1[0] = c1[2];
				c1[1] = c1[3];
			}
*/
			mes = atoi(c1);

			c1 = strchr(c1,'/');
			c1++;


			anio = atoi(c1);

			

			actual.setDate(tiempo.wYear, tiempo.wMonth, tiempo.wDay);
			expira.setDate(anio,mes,dia);

			dias_restantes = actual.daysTo(expira);

			QLinearGradient gradient2(0, 0, 0, 30);

			if (dias_restantes >= 14)
			{
				gradient2.setColorAt(0, QColor::fromRgb(0, 255, 0,170));
				gradient2.setColorAt(1, QColor::fromRgb(116, 116, 116,170));
			}
			else if (dias_restantes > 7)
			{
				gradient2.setColorAt(0, QColor::fromRgb(255, 255, 0,170));
				gradient2.setColorAt(1, QColor::fromRgb(116, 116, 116,170));
			}
			else
			{
				gradient2.setColorAt(0, QColor::fromRgb(255, 0, 0,170));
				gradient2.setColorAt(1, QColor::fromRgb(116, 116, 116,170));
			}
			QBrush brush2(gradient2);

			QTableWidgetItem * rest = new QTableWidgetItem;

			rest->setBackground(brush2);
			rest->setData(Qt::DisplayRole,dias_restantes);
			rest->setText(QString::number(dias_restantes));
			ui.Tabla->setItem(i,5,rest);

		}
	}
	
	ui.Tabla->sortItems(5,Qt::AscendingOrder);

	
}
void GTD::on_Busqueda_textChanged(const QString & text)
{
	int i,j;

	ui.Lista_Busqueda->clear();

	if (ui.Busqueda->text() != "")
	{
		for (i=0; i< numero_elementos;i++)
		{
			QTableWidgetItem * elemento3 = new QTableWidgetItem;
			QTableWidgetItem * elemento4 = new QTableWidgetItem;
			QTableWidgetItem * elemento5 = new QTableWidgetItem;
			elemento3 = ui.Tabla->item(i,0);
			elemento4 = ui.Tabla->item(i,1);
			elemento5 = ui.Tabla->item(i,2);
			if ((elemento3->text().contains(ui.Busqueda->text(),Qt::CaseInsensitive)) || (elemento4->text().contains(ui.Busqueda->text(),Qt::CaseInsensitive)) || (elemento5->text().contains(ui.Busqueda->text(),Qt::CaseInsensitive)))
			{
				ui.Lista_Busqueda->addItem(QString::number(i) + " " +elemento3->text() + " " + elemento4->text() + " " +elemento5->text());
			}
			
		}
	}
}

void GTD::on_Lista_Busqueda_itemDoubleClicked(QListWidgetItem * item)
{
	QString texto;
	static int i;
	char * pch;
	char * expresion;
	QByteArray c1iliar;
	char * c1;
	int posicion = 0;

	texto = item->text();

	c1iliar = texto.toLocal8Bit();

	c1 = c1iliar.data();

	posicion = atoi(c1);

			int a;

			QTableWidgetItem * elemento5 = new QTableWidgetItem;
			QTableWidgetItem * elemento6 = new QTableWidgetItem;
			QTableWidgetItem * elemento7 = new QTableWidgetItem;
			QTableWidgetItem * elemento8 = new QTableWidgetItem;
			QTableWidgetItem * elemento9 = new QTableWidgetItem;
			QTableWidgetItem * elemento10 = new QTableWidgetItem;

			ui.Formulario->setVisible(true);
			
			elemento5 = ui.Tabla->item(posicion,0);
			elemento6 = ui.Tabla->item(posicion,1);
			elemento7 = ui.Tabla->item(posicion,2);
			elemento8 = ui.Tabla->item(posicion,3);



			ui.Nombre->setText(elemento5->text());
			ui.Lentillas->setText(elemento6->text());
			ui.Observaciones->setText(elemento7->text());
			ui.Fecha_Entrada->setText(elemento8->text());

			DNI_modificar = elemento7->text();
			
			modificar = 1;
			fila_seleccionada = posicion;

}