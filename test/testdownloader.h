#ifndef TESTDOWNLOADER_H
#define TESTDOWNLOADER_H


#include "onedayprice.h"
#include <QtCore/QObject>
#include <memory>
#include "downloader.h"

using namespace std;

namespace testdownloader
{
class Test : public QObject
{
	Q_OBJECT;
public:
	Test();

private slots:
	void onfinish(std::shared_ptr<std::vector<ONEDAYPRICE> > pvec);

public:
	Downloader downloader;
};
}


#endif
