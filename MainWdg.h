#pragma once

#include <QtWidgets>

class CMainWdg : public QWidget
{
	Q_OBJECT;
public:
	CMainWdg(QWidget* parent = nullptr);
private:
	QVBoxLayout* m_mainVBL;
	QSystemTrayIcon *m_systemTray;
private slots:
	void onActivated(QSystemTrayIcon::ActivationReason reason);
};