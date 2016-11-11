#pragma once

/*日志基类*/
enum LogLevel {
	LOG_LEVEL_DEBUG = 0,
	LOG_LEVEL_INFO = 1,
	LOG_LEVEL_WARN =2,
	LOG_LEVEL_ERROR = 3
};

class CLogger
{
public:
	void Debug(LPCTSTR pstrFormat, ...);
	void Info(LPCTSTR pstrFormat, ...);
	void Warn(LPCTSTR pstrFormat, ...);
	void Error(LPCTSTR pstrFormat, ...);

private:
	CString FormatTime(int nTime);

protected:
	int m_nLogLevel;
	CString FormatLog(enum LogLevel eLevel, CString strLog);
	virtual void WriteLog(CString strLog) = 0;
public:
	CLogger();
	virtual ~CLogger();
};

