#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <QDate>
#include <QDateTime>




void fileout(int para)
{
	QString filename = "";
	QString strline;


	switch(para)
	{
		case 1:
			filename = "testpass.txt";
			break;
		case 2:
			filename = "testfail.txt";
			break;
	}

	QFile file(qApp->applicationDirPath()+ "/" + filename);
	if(file.exists())
	{
		if(file.open(QIODevice::ReadOnly | QIODevice::Text)== true)
		{
			while(!file.atEnd())
			{
				QTextStream(stdout) << file.readLine();
			}
			file.close();
		}
		else
		{
			QTextStream(stdout) << "file can not open!" << endl;
		}
	}
	else
	{
		QTextStream(stdout) << "file not found!" << endl;
	}
}

void writeUnitXml()
{
	QTime time;
	QDate date;
	QString strTime;
	QString strDate;


	time = QTime::currentTime();
	strTime = time.toString(Qt::TextDate);

	QDateTime asd(QDateTime::currentDateTime());
	uint unixTime = asd.toTime_t();

	date = QDate::currentDate();
	strDate = asd.toString("yyyy-mm-ddThh:mm:ss");

	QFile file(qApp->applicationDirPath()+ "/" + "test.xml");
	if(file.open(QIODevice::WriteOnly | QIODevice::Text)== true)
	{


		file.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
		file.write("<testsuites>\n");
		file.write("  <testsuite name=\"AvmTool - AvmSetId\" tests=\"10\" failures=\"1\" skipped=\"1\" time=\"" +QByteArray::number(unixTime) + "\" timestamp=\"" + strDate.toLatin1()+ "\" id=\"39f13ba7-6820-d6dc-8165-76fbcceabc7e\" log=\"\">\n");
		file.write("	<testcase name=\"AvmSetId - Version\" time=\"" +QByteArray::number(unixTime) + "\" timestamp=\"" + strDate.toLatin1()+ ".6008759+01:00\" log=\"+ Passed AvmSetId - Version&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"AvmSetId - open database connection\" time=\"93.8767338\" timestamp=\"" + strDate.toLatin1()+ ".9749463+01:00\" log=\"+ Passed AvmSetId - open database connection&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"AvmSetId - load macs from database\" time=\"143.0023053\" timestamp=\"" + strDate.toLatin1()+ ".3683063+01:00\" log=\"+ Failed AvmSetId - macs successfully loaded!&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"AvmSetId - macs successfully loaded!\" time=\"\" timestamp=\"\">\n");
		file.write("	<skipped />\n");
		file.write("	</testcase>\n");
		file.write("  </testsuite>\n");
		file.write("</testsuites>\n");

/*
		<?xml version="1.0" encoding="UTF-8"?>
		<testsuites>
		   <testsuite name="JUnitXmlReporter" errors="0" tests="0" failures="0" time="0" timestamp="2013-05-24T10:23:58" />
		   <testsuite name="JUnitXmlReporter.constructor" errors="0" skipped="1" tests="3" failures="1" time="0.006" timestamp="2013-05-24T10:23:58">
			  <properties>
				 <property name="java.vendor" value="Sun Microsystems Inc." />
				 <property name="compiler.debug" value="on" />
				 <property name="project.jdk.classpath" value="jdk.classpath.1.6" />
			  </properties>
			  <testcase classname="JUnitXmlReporter.constructor" name="should default path to an empty string" time="0.006">
				 <failure message="test failure">Assertion failed</failure>
			  </testcase>
			  <testcase classname="JUnitXmlReporter.constructor" name="should default consolidate to true" time="0">
				 <skipped />
			  </testcase>
			  <testcase classname="JUnitXmlReporter.constructor" name="should default useDotNotation to true" time="0" />
		   </testsuite>
		</testsuites>
*/



		file.close();
	}

}

int main(int argc, char *argv[])
{
	int iPara=0;
	QCoreApplication a(argc, argv);
	for ( int i = 0; i < argc ; ++i )
	{
		QTextStream(stdout) << argv[i] << endl;
		if(QString("testpara=1").compare(argv[i]) == 0)
		{
			iPara=1;
		}
		else if(QString("testpara=2").compare(argv[i]) == 0)
		{
			iPara=2;
		}

	}
	QTextStream(stdout) << "Hello World!" << endl;
	fileout(iPara);
	writeUnitXml();
	return 0;
}
