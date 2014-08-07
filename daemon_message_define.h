#ifndef __DAEMON_MESSAGE_DEFINE_H
#define __DAEMON_MESSAGE_DEFINE_H

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
//#include "frame/impl/frame_protocol_impl.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN
#ifndef CLOSE_NOTIFY_EVENT
#define CLOSE_NOTIFY_EVENT					0xFFFFFFFF
#endif

//服务器断线通知,ROUTER 发往 DAEMON
#define MSGID_DAEMON_REGIST_NOTIFY			0x00130201
//空体
class CDaemonRegistNotify_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDaemonRegistNotify_Public()
	{
	}

	virtual ~CDaemonRegistNotify_Public()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "this is the Server register, msgbody: {serverID = %d, serverType = %d}", serverID, (int32_t)serverType);
		offset = (uint32_t)strlen(buf);
	}

public:
	ServerID		serverID;
	EntityType		serverType;
};
//服务器断线通知,ROUTER 发往 DAEMON
#define MSGID_DAEMON_UNREGIST_NOTIFY		0x00130202
class CDaemonUnregistNotify_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDaemonUnregistNotify_Public()
	{

	}

	virtual ~CDaemonUnregistNotify_Public()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "this is the Server unregister, msgbody: {serverID = %d, serverType = %d}", serverID, (int32_t)serverType);
		offset = (uint32_t)strlen(buf);
	}

public:
	ServerID		serverID;
	EntityType		serverType;
};

//DAEMON广播给所有服务器的某个服务器的上线通知
#define MSGID_DAEMON_START_NOTIFY		0x00130E01
class CDaemonStartNotify_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDaemonStartNotify_Public()
	{

	}

	virtual ~CDaemonStartNotify_Public()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "this is the start server notify, {serverID = %d, serverType = %d}", serverID, (int32_t)serverType);
		offset = (uint32_t)strlen(buf);
	}

public:
	ServerID		serverID;
	EntityType		serverType;
};

//DAEMON广播给所有服务器的某个服务器的断线通知
#define MSGID_DAEMON_STOP_NOTIFY		0x00130E02
class CDaemonStopNotify_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDaemonStopNotify_Public()
	{

	}

	virtual ~CDaemonStopNotify_Public()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, serverID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, serverType);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "this is the stop server notify, {serverID = %d, serverType = %d}", serverID, (int32_t)serverType);
		offset = (uint32_t)strlen(buf);
	}

public:
	ServerID		serverID;
	EntityType		serverType;
};

MESSAGEMAP_DECL_BEGIN(daemonserver)
MESSAGEMAP_DECL_MSG(MSGID_DAEMON_REGIST_NOTIFY, (new CDaemonRegistNotify_Public()))
MESSAGEMAP_DECL_MSG(MSGID_DAEMON_UNREGIST_NOTIFY, (new CDaemonUnregistNotify_Public()))
MESSAGEMAP_DECL_MSG(CLOSE_NOTIFY_EVENT, NULL)
MESSAGEMAP_DECL_MSG(MSGID_DAEMON_START_NOTIFY, (new CDaemonStartNotify_Public()))
MESSAGEMAP_DECL_MSG(MSGID_DAEMON_STOP_NOTIFY, (new CDaemonStopNotify_Public()))
MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif
