/*
 * roomdispatcher_message_define.h
 *
 *  Created on: 2012-4-23
 *      Author: jimm
 */

#ifndef ROOMDISPATCHER_MESSAGE_DEFINE_H_
#define ROOMDISPATCHER_MESSAGE_DEFINE_H_

#include "common/common_string.h"
#include "../lightframe/frame_namespace.h"
#include "../lightframe/frame_typedef.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "../lightframe/lightframe_impl.h"
#include "common/common_singleton.h"
#include <stdio.h>
#include <string.h>

FRAME_NAMESPACE_BEGIN

#define MSGID_RDRS_BUILDROOMDATA_NOTI			0x00131001
class CBuildRoomDataNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBuildRoomDataNoti()
	{
		nRoomDataSize = 0;
		memset(arrRoomData, 0, sizeof(arrRoomData));
	}

	virtual ~CBuildRoomDataNoti()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomDataSize);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, arrRoomData, nRoomDataSize, sizeof(arrRoomData));
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomDataSize);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, arrRoomData, nRoomDataSize, sizeof(arrRoomData));
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomDataSize=%d, nRoomID=%u}", nRoomDataSize, *((RoomID *)((uint8_t *)arrRoomData + 4)));
		offset = (uint32_t)strlen(buf);
	}

public:
	uint32_t				nRoomDataSize;
	uint8_t					arrRoomData[RoomCacheSize];
};

#define MSGID_RDRS_BUILDPLAYERDATA_NOTI			0x00131002
class CBuildPlayerDataNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBuildPlayerDataNoti()
	{

	}

	virtual ~CBuildPlayerDataNoti()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerCount);
		if(nRet < 0)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrPlayerDataSize[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrPlayerData[i], arrPlayerDataSize[i], PlayerCacheSize);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerCount);
		if(nRet < 0)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrPlayerDataSize[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nPlayerCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrPlayerData[i], arrPlayerDataSize[i], PlayerCacheSize);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d,nPlayerCount=%d, arrPlayerDataSize={", nRoomID, nPlayerCount);
		offset = (uint32_t)strlen(buf);

		if(nPlayerCount > 0)
		{
			for(int32_t i = 0; i < nPlayerCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrPlayerDataSize[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrRoleID={", arrPlayerDataSize[nPlayerCount - 1]);
			offset = (uint32_t)strlen(buf);

			for(int32_t i = 0; i < nPlayerCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoleID[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}}", arrRoleID[nPlayerCount - 1]);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "}, arrRoleID={}}");
			offset = (uint32_t)strlen(buf);
		}
	}

public:
	RoomID					nRoomID;
	int32_t					nPlayerCount;
	uint32_t				arrPlayerDataSize[MaxBuildPlayerDataCount];
	RoleID					arrRoleID[MaxBuildPlayerDataCount];
	uint8_t					arrPlayerData[MaxBuildPlayerDataCount][PlayerCacheSize];
};

#define MSGID_RDRS_SETMEIDAINFO_NOTI			0x00131003
class CSetMediaInfoNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID		nRoomID;
	uint32_t	nTelMediaIP;
	uint16_t	nTelMediaPort;
	ServerID    nTelServerID;  //电信media的ID
	uint32_t	nCncMediaIP;
	uint16_t	nCncMediaPort;
	ServerID    nCncServerID;  //网通media的ID

	CSetMediaInfoNoti()
	{
		nRoomID = enmInvalidRoomID;
		nTelMediaIP = 0;
		nTelMediaPort = 0;
		nTelServerID = enmInvalidServerID;
		nCncMediaIP = 0;
		nCncMediaPort = 0;
		nCncServerID = enmInvalidServerID;
	}

	virtual ~CSetMediaInfoNoti()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size,
			uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nTelMediaIP);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTelMediaPort);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTelServerID);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncMediaIP);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncMediaPort);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncServerID);
		if (nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size,
			uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nTelMediaIP);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTelMediaPort);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTelServerID);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncMediaIP);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncMediaPort);
		if (nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncServerID);
		if (nRet < 0)
		{
			return nRet;
		}
		return nRet;
	}
public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{nTelMediaIp=%s, nTelMediaPort=%d,nTelServerID=%d, ",
				inet_ntoa_f(nTelMediaIP), nTelMediaPort, nTelServerID);
		offset = (uint32_t) strlen(buf);
		sprintf(buf + offset,
				"nCncMediaIp=%s, nCncMediaPort=%d,nCncServerID=%d}",
				inet_ntoa_f(nCncMediaIP), nCncMediaPort, nCncServerID);
		offset = (uint32_t) strlen(buf);
	}
};
MESSAGEMAP_DECL_BEGIN(roomdispatcher)

MESSAGEMAP_DECL_MSG(MSGID_RDRS_BUILDROOMDATA_NOTI, (new CBuildRoomDataNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RDRS_BUILDPLAYERDATA_NOTI, (new CBuildPlayerDataNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RDRS_SETMEIDAINFO_NOTI, (new CSetMediaInfoNoti()))

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* ROOMDISPATCHER_MESSAGE_DEFINE_H_ */
