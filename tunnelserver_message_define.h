/*
 * tunnelserver_message_define.h
 *
 *  Created on: 2011-12-6
 *      Author: jimm
 */

#ifndef TUNNELSERVER_MESSAGE_DEFINE_H_
#define TUNNELSERVER_MESSAGE_DEFINE_H_

#include "frame_namespace.h"
#include "frame_typedef.h"
//#include "frame/impl/frame_protocol_impl.h"
#include "common/common_codeengine.h"
#include "./public_typedef.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

//用户登陆信息请求
#define MSGID_TSHS_GETROOMSERVERID_REQ			0x00110601
class CGetRoomServerIDReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoleID=%d, nRoomID=%d, nConnIndex=%d}", nRoleID, nRoomID, nConnIndex);
	    offset = (uint32_t)strlen(buf);
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
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
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
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
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}
public:
	RoleID			nRoleID;
	RoomID			nRoomID;
	ConnIndex		nConnIndex;
};

//用户登陆信息响应
#define MSGID_HSTS_GETROOMSERVERID_RESP			0x00120402
class CGetRoomServerIDResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nResult=0x%08x, nRoleID=%d, nRoomID=%d, nServerID=%d, nConnIndex=%d}",
	    		nResult, nRoleID, nRoomID, nServerID, nConnIndex);
	    offset = (uint32_t)strlen(buf);
	}
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
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
		nRet = CCodeEngine::Encode(buf, size, offset, nServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}
	int32_t	MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}
public:
	int32_t			nResult;
	RoleID			nRoleID;
	RoomID			nRoomID;
	ServerID		nServerID;
	ConnIndex		nConnIndex;
};


//获取玩家的179roleid请求
#define MSGID_TSDB_GETEXTERNALPLAYERROLEID_REQ				0x00110602
class CGetExternalPlayerRoleIDReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetExternalPlayerRoleIDReq()
	{
		nConnIndex = 0;
		nAccountType = 0;
		nFromIP = 0;
		nUin = enmInvalidRoleID;
	}

	virtual ~CGetExternalPlayerRoleIDReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nAccountType);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nFromIP);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nUin);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nAccountType);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nFromIP);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nUin);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nConnIndex=%d, nAccountType=%d, nFromIP=%s, nUin=%d}",
				nConnIndex, nAccountType, inet_ntoa_f(nFromIP), nUin);
	    offset = (uint32_t)strlen(buf);
	}
public:
	ConnIndex					nConnIndex;
	AccountType					nAccountType;		//用户类型，即来自哪里
	uint32_t					nFromIP;			//来源IP，即用户的IP
	int32_t						nUin;				//来源地的uin
};

//获取玩家的179roleid响应
#define MSGID_DBTS_GETEXTERNALPLAYERROLEID_RESP				0x00120602
class CGetExternalPlayerRoleIDResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetExternalPlayerRoleIDResp()
	{
		nResult = 0;
		nConnIndex = 0;
		nRoleID = enmInvalidRoleID;
	}

	virtual ~CGetExternalPlayerRoleIDResp()
	{

	}

	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == S_OK)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == S_OK)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nConnIndex=%d", nResult, nConnIndex);
	    offset = (uint32_t)strlen(buf);
	    if(nResult == S_OK)
	    {
	    	sprintf(buf + offset, "nRoleID=%d}", nRoleID);
	    }
	    else
	    {
	    	sprintf(buf + offset, "}");
	    }
	    offset = (uint32_t)strlen(buf);
	}
public:
	int32_t					nResult;
	ConnIndex				nConnIndex;
	RoleID					nRoleID;			//179uin
};

////更新大厅服务器 player及room 数据通知
//#define MSGID_HSTS_PLAYERUPDATE_NOTI			0x00130603

//大厅服务器恢复 player 数据通知
#define MSGID_TSHS_HALLBUILDPLAYER_NOTI			0x00130604
class CRecoverHallPlayerNoti_public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRecoverHallPlayerNoti_public(){}
	virtual ~CRecoverHallPlayerNoti_public(){}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
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
		sprintf(buf + offset, "{nPlayerCount=%d, arrPlayerDataSize={", nPlayerCount);
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
			sprintf(buf + offset, "%d}}\n", arrRoleID[nPlayerCount - 1]);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "}, arrRoleID={}}\n");
			offset = (uint32_t)strlen(buf);
		}
	}

public:
	int32_t					nPlayerCount;
	uint32_t				arrPlayerDataSize[MaxBuildPlayerDataCount];
	RoleID					arrRoleID[MaxBuildPlayerDataCount];
	uint8_t					arrPlayerData[MaxBuildPlayerDataCount][PlayerCacheSize];
};

//大厅服务器恢复 room 数据通知
#define MSGID_TSHS_HALLBUILDROOM_NOTI			0x00130605
class CRecoverHallRoomNoti_public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRecoverHallRoomNoti_public(){}

	virtual ~CRecoverHallRoomNoti_public(){}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomCount);
		if(nRet < 0)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoomDataSize[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoomID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoomData[i], arrRoomDataSize[i], HallRoomCacheSize);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomCount);
		if(nRet < 0)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoomDataSize[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoomID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoomData[i], arrRoomDataSize[i], HallRoomCacheSize);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomCount=%d, arrRoomDataSize={", nRoomCount);
		offset = (uint32_t)strlen(buf);

		if(nRoomCount > 0)
		{
			for(int32_t i = 0; i < nRoomCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoomDataSize[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrRoomID={", arrRoomDataSize[nRoomCount - 1]);
			offset = (uint32_t)strlen(buf);

			for(int32_t i = 0; i < nRoomCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoomID[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}}\n", arrRoomID[nRoomCount - 1]);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "}, arrRoomID={}}\n");
			offset = (uint32_t)strlen(buf);
		}
	}


public:
	int32_t					nRoomCount;
	uint32_t				arrRoomDataSize[MaxBuildRoomDataCount];
	RoomID					arrRoomID[MaxBuildRoomDataCount];
	uint8_t					arrRoomData[MaxBuildRoomDataCount][HallRoomCacheSize];
};

//恢复给大厅的room 和 player 数据总数
#define MSGID_TSHS_UPDATEDATANUM_NOTI			0x00130606
class CTunnelUpdateDataNumNoti_public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	uint32_t		nRoomNum;					//room 对象总数
	uint32_t		nPlayerNum;					//player对象总数
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomNum);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerNum);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomNum);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerNum);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomNum=%u, nPlayerNum=%u", nRoomNum, nPlayerNum);
		offset = (uint32_t)strlen(buf);
	}
};

//统计用户的网络环境
#define MSGID_TSDB_ROOM_COLLECTION_INF0_NOTICE   0x00018030
class CRoomCollectInfoNotice: public IMsgBody
{
	SIZE_INTERFACE();
public:
	uint16_t nCount;
	CString<MaxRoomCollectionKeyLen>  strCollectionKey[MaxRoomCollectionInfoCount];
	CString<MaxRoomCollectionContentLen>  strCollectionContent[MaxRoomCollectionInfoCount];
public:
	CRoomCollectInfoNotice()
	{
		nCount = 0;
		for(uint16_t i=0; i<nCount; ++i)
		{
			strCollectionKey[i].Initialize();
			strCollectionContent[i].Initialize();
		}
	}
	virtual ~CRoomCollectInfoNotice(){}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(uint16_t i=0; i<nCount; ++i)
		{
			ret = strCollectionKey[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = strCollectionContent[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(uint16_t i=0; i<nCount; ++i)
		{
			ret = strCollectionKey[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = strCollectionContent[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "room collection information, nCount=%d, ", nCount);
		offset = (uint32_t)strlen(buf);
		for(uint16_t i=0; i<nCount; ++i)
		{
			sprintf(buf + offset, "key[%d]=%s, content[%d]=%s, ", 
				i, strCollectionKey[i].GetString(), i, strCollectionContent[i].GetString());
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);
	}
};

//用户登陆信息请求
#define MSGID_CLIENTDB_GETFANS_REQ			0x00018035
class CClientGetFansReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID       nRoleID;      //与协议文档保持一致， RoleID是int32_t型， 不是uint32_t型

public:
	CClientGetFansReq()
	{
		nRoleID = enmInvalidRoleID;
	}
	virtual ~CClientGetFansReq(){}

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d}", nRoleID);
		offset = (uint32_t)strlen(buf);
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}
};

//用户登陆信息响应
#define MSGID_CLIENTDB_GETFANS_RESP			0x00020735
class CClientGetFansResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t			nResult;
	uint8_t         nCountDay;    //日粉丝榜人数
	RoleID          arrDayRoleID[MaxFansCountPerType];
	CString<MaxRoleNameLength>  arrDayRoleName[MaxFansCountPerType];
	uint32_t        arrDayMoney[MaxFansCountPerType];
	uint8_t         nCountMonth;  //月粉丝榜人数
	RoleID          arrMonthRoleID[MaxFansCountPerType];
	CString<MaxRoleNameLength>  arrMonthRoleName[MaxFansCountPerType];
	uint32_t        arrMonthMoney[MaxFansCountPerType];
	uint8_t         nCountAll;  //月粉丝榜人数
	RoleID          arrAllRoleID[MaxFansCountPerType];
	CString<MaxRoleNameLength>  arrAllRoleName[MaxFansCountPerType];
	uint32_t        arrAllMoney[MaxFansCountPerType];

public:
	CClientGetFansResp()
	{
		nResult = S_OK;
		nCountDay = 0;
		memset(arrDayRoleID, 0, sizeof(arrDayRoleID));
		for(uint8_t i=0; i<MaxFansCountPerType; ++i)
		{
			arrDayRoleName[i].Initialize();
		}
		memset(arrDayMoney, 0, sizeof(arrDayMoney));
		nCountMonth = 0;
		memset(arrMonthRoleID, 0, sizeof(arrMonthRoleID));
		for(uint8_t i=0; i<MaxFansCountPerType; ++i)
		{
			arrMonthRoleName[i].Initialize();
		}
		memset(arrMonthMoney, 0, sizeof(arrMonthMoney));
		nCountAll = 0;
		memset(arrAllRoleID, 0, sizeof(arrAllRoleID));
		for(uint8_t i=0; i<MaxFansCountPerType; ++i)
		{
			arrAllRoleName[i].Initialize();
		}
		memset(arrAllMoney, 0, sizeof(arrAllMoney));
	}

	virtual ~CClientGetFansResp(){}

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, ", nResult);
		offset = (uint32_t)strlen(buf);

		if(0 > nResult)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			return;
		}

		for(uint8_t i=0; i<nCountDay && i<MaxFansCountPerType; ++i)
		{
			sprintf(buf + offset, "{arrDayRoleID[%d]=%d, arrDayRoleName[%d]=%s}, arrDayMoney[%d]=%d, ", 
				i, arrDayRoleID[i], i, arrDayRoleName[i].GetString(), i, arrDayMoney[i]);
			offset = (uint32_t)strlen(buf);
		}	
		offset = (uint32_t)strlen(buf);

		for(uint8_t i=0; i<nCountMonth && i<MaxFansCountPerType; ++i)
		{
			sprintf(buf + offset, "{nRoleID[%d]=%d, strRoleName[%d]=%s}, arrMonthMoney[%d]=%d, ", 
				i, arrMonthRoleID[i], i, arrMonthRoleName[i].GetString(), i, arrMonthMoney[i]);
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);

		for(uint8_t i=0;  i<nCountAll && i<MaxFansCountPerType; ++i)
		{
			sprintf(buf + offset, "{nAllRoleID[%d]=%d, strAllName[%d]=%s}, arrAllMoney[%d]=%d, ", 
				i, arrAllRoleID[i], i, arrAllRoleName[i].GetString(), i, arrAllMoney[i]);
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);

		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}

	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}

		if(0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Encode(buf, size, offset, nCountDay);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountDay && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrDayRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrDayRoleName[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrDayMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		ret = CCodeEngine::Encode(buf, size, offset, nCountMonth);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountMonth && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrMonthRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrMonthRoleName[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrMonthMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		ret = CCodeEngine::Encode(buf, size, offset, nCountAll);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountAll && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrAllRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrAllRoleName[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrAllMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		return S_OK;
	}

	int32_t	MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}

		if(0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nCountDay);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountDay && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrDayRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrDayRoleName[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrDayMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		ret = CCodeEngine::Decode(buf, size, offset, nCountMonth);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountMonth && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrMonthRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrMonthRoleName[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrMonthMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		ret = CCodeEngine::Decode(buf, size, offset, nCountAll);
		if(0 > ret)
		{
			return ret;
		}

		for(uint8_t i=0; i<nCountAll && i<MaxFansCountPerType; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrAllRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrAllRoleName[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrAllMoney[i]);
			if(0 > ret)
			{
				return ret;
			}
		}

		return S_OK;
	}
};


MESSAGEMAP_DECL_BEGIN(tunnelserver)

MESSAGEMAP_DECL_MSG(MSGID_TSDB_GETEXTERNALPLAYERROLEID_REQ, (new CGetExternalPlayerRoleIDReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBTS_GETEXTERNALPLAYERROLEID_RESP, (new CGetExternalPlayerRoleIDResp()))
MESSAGEMAP_DECL_MSG(MSGID_TSDB_ROOM_COLLECTION_INF0_NOTICE, (new CRoomCollectInfoNotice()))
MESSAGEMAP_DECL_MSG(MSGID_CLIENTDB_GETFANS_REQ, (new CClientGetFansReq()))
MESSAGEMAP_DECL_MSG(MSGID_CLIENTDB_GETFANS_RESP, (new CClientGetFansResp()))

MESSAGEMAP_DECL_MSG(MSGID_HSTS_GETROOMSERVERID_RESP, (new CGetRoomServerIDResp_Public()))


MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* TUNNELSERVER_MESSAGE_DEFINE_H_ */

