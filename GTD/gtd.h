#ifndef GTD_H
#define GTD_H

#include <QtGui/QMainWindow>
#include "ui_gtd.h"

class GTD : public QMainWindow
{
	Q_OBJECT

public:
	GTD(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GTD();

private:
	Ui::GTDClass ui;

	public slots:
		void on_Aceptar_clicked();
		void on_Nuevo_clicked();
		void on_Cancelar_clicked();
		void on_Tabla_cellClicked(int row, int column);
		void on_Tabla_cellDoubleClicked(int row, int column);
		void on_Eliminar_clicked();
		void on_Fecha_Entrada_clicked();
		void on_Calendario_selectionChanged();
		void on_Busqueda_textChanged(const QString & text);
		void on_Lista_Busqueda_itemDoubleClicked(QListWidgetItem * item);

		void cambio();
};

#endif // GTD_H
