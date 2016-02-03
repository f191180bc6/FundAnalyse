#include <iostream>
#include <stdio.h>
#include "downloader.h"
#include "onedayprice.h"
#include <QtCore/QObject>
#include <algorithm>
#include "testdownloader.h"
#include <QtGui/QApplication>
#include <QtCore/QDebug>

using namespace std;
using namespace testdownloader;

Test::Test()
{
	connect(&downloader, SIGNAL(finish(std::shared_ptr<std::vector<ONEDAYPRICE> > )),
			this, SLOT(onfinish(std::shared_ptr<std::vector<ONEDAYPRICE> > )));
}

void Test::onfinish(std::shared_ptr<std::vector<ONEDAYPRICE> > pvec)
{
	std::vector<ONEDAYPRICE> &vec = *pvec;
	for_each(vec.begin(), vec.end(), [](ONEDAYPRICE &price)
			 {
				 qDebug() << price.date.year() << " "
						  << price.date.month() << " "
						  << price.date.day()  << "  "
						  << price.dPrice;
			 });
	QApplication::instance()->quit();
}

int main_testdownloader(int argc, char **argv)
{

	QApplication app(argc, argv);

	testdownloader::Test test;
	test.downloader.Download(200009, 50);
 
	return app.exec();
}
