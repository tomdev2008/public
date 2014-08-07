/*
 * mediaserver_message_define.h
 *
 *  Created on: 2013-1-16
 *      Author: gaox
 */

#ifndef MEDIASERVER_MESSAGE_DEFINE_H_
#define MEDIASERVER_MESSAGE_DEFINE_H_

#include <string>
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "common/common_errordef.h"
#include "common/common_codeengine.h"
#include "common/common_api.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "public_typedef.h"

FRAME_NAMESPACE_BEGIN

#define MAX_PACKET_SIZE			1492 									//包中数据字段的最大长度(不包括包头)
#define SERVER_MAX_SIZE		(MAX_PACKET_SIZE + MESSAGEHEADSS_SIZE) 		//Tcp协议包的最大长度

#define MAX_BUFFER_SIZE			(32 * 1024)

//注册、心跳
#define MSGID_REG		0x0001

//转发音频文件
#define MSGID_TRANSMIT_AUDIO		0x0002
//转发视频文件
#define MSGID_TRANSMIT_VIDEO		0x0003

//获取语音补尝请求
#define MSGID_TRANSMIT_GET_AUDIO	0x0005
#define MSGID_TRANSMIT_GET_VIDEO	0x0006
#define MSGID_KEEPLIVE				0x0007

#define		MSGID_MSTS_REGISTE				0x0008
#define		MSGID_MSTS_UNREGISTE			0x0009
#define		MSGID_MSTS_RELEASE				0x000A

#define CMEDIAHEADCS_SIZE	16
class CMediaHeadCs
{
public:
	CMediaHeadCs()
	{
		nMsgID = 0;
		nDataSize = 0;
		nSeq = 0;
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
	}
	virtual ~CMediaHeadCs()
	{

	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nMsgID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nDataSize);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nSeq);
		if(0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nMsgID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nDataSize);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nSeq);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{MsgID=%d, nRoleID=%d, nRoomID=%d, nDataSiae=%d, nSeq=%d}", nMsgID,nRoleID,nRoomID,nDataSize, nSeq);
		offset = (uint32_t)strlen(buf);
	}
public:
	uint16_t nMsgID;
	RoleID nRoleID;
	RoomID nRoomID;
	uint16_t nDataSize;
	uint32_t nSeq;
};

//class CRegisteTransmiterNoti : public IMsgBody
//{
//public:
//	CRegisteTransmiterNoti()
//	{
//	}
//
//	virtual ~CRegisteTransmiterNoti()
//	{
//
//	}
//
//	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
//	{
//		return S_OK;
//	}
//
//	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
//	{
//		return S_OK;
//	}
//
//	void Dump(char* buf, const uint32_t size, uint32_t& offset)
//	{
//		sprintf(buf + offset, "{Nothing}");
//		offset = (uint32_t)strlen(buf);
//	}
//public:
//
//};

#define MSGID_MSRS_REGISTADDRESSINFO_NOTICE			0x00130501
class CRegistAddressInfoNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRegistAddressInfoNoti()
	{
		nInternetAddress = 0;
		nInternetPort = 0;
	}

	virtual ~CRegistAddressInfoNoti()
	{
	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nInternetAddress);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nInternetPort);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nInternetAddress);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nInternetPort);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nInternetAddress=%s, nInternetPort=%d}\n",
				inet_ntoa_f(nInternetAddress), nInternetPort);
		offset = (uint32_t)strlen(buf);
	}
public:
	uint32_t			nInternetAddress;			//外网地址
	uint16_t			nInternetPort;				//外网端口
};

MESSAGEMAP_DECL_BEGIN(mediaserver)

MESSAGEMAP_DECL_MSG(MSGID_MSRS_REGISTADDRESSINFO_NOTICE, (new CRegistAddressInfoNoti()))

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* MEDIASERVER_MESSAGE_DEFINE_H_ */
