#include "gtd.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GTD w;
	w.show();
	return a.exec();
}
