/*
 *  roomserver_message_define.h
 *
 *  To do��                        ��roomserver�����message
 *  Created on: 	2011-12-8
 *  Author: 		luocj
 */

#ifndef ROOMSERVER_MESSAGE_DEFINE_H_
#define ROOMSERVER_MESSAGE_DEFINE_H_

#include "public_typedef.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_msg_impl.h"
//#include "frame/impl/frame_protocol_impl.h"
#include "common/common_string.h"
#include "common/common_api.h"
#include "common/common_singleton.h"
#include "common/common_codeengine.h"

#include <stdio.h>

FRAME_NAMESPACE_BEGIN

//��ȡ�û���Ϣ����
#define MSGID_RSDB_GETROLEINFO_REQ		0x00110701
class CGetRoleInfoReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoleID=%d}", nRoleID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	CGetRoleInfoReq_Public()
	{
		nRoleID = enmInvalidRoleID;
	}
	RoleID			nRoleID;
};


//��ȡ�û���Ϣ��Ӧ
#define MSGID_DBRS_GETROLEINFO_RESP		0x00120701
class CGetRoleInfoResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult < 0)
		{

		}
		else
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nPlayerGender);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nMoney);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nOnlineTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nPunishType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nPunishEndTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nPunishReason);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nRoomCount);
			if (0 > nRet)
			{
				return nRet;
			}
			if(nRoomCount>MaxBeAdminPerPlayer)
			{
				return ENCODE_DECODE_FILED;
			}
			for(int32_t i = 0;i<nRoomCount&&i<MaxBeAdminPerPlayer;i++)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrRoomID[i]);
				if (0 > nRet)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrRoleRank[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nIdentityType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nOnMicTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nAccountID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = strRoleName.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSelfSetting);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nLoginTimes);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nCollectCount);
			if (0 > nRet)
			{
				return nRet;
			}
			for(uint16_t i = 0; i < nCollectCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrCollectRoomList[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult < 0)
		{

		}
		else
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nPlayerGender);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nMoney);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nOnlineTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nPunishType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nPunishEndTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nPunishReason);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nRoomCount);
			if (0 > nRet)
			{
				return nRet;
			}
			if(nRoomCount>MaxBeAdminPerPlayer)
			{
				return ENCODE_DECODE_FILED;
			}
			for(int32_t i = 0;i<nRoomCount&&i<MaxBeAdminPerPlayer;i++)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrRoomID[i]);
				if (0 > nRet)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrRoleRank[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nIdentityType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nOnMicTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nAccountID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = strRoleName.MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nSelfSetting);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nLoginTimes);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nCollectCount);
			if (0 > nRet)
			{
				return nRet;
			}
			for(uint16_t i = 0; i < nCollectCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrCollectRoomList[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoleID=%d,nPlayerGender=%d,nVipLevel=%d,nMoney=%d,"
	    		"nOnlineTime=%d,nPunishType=%d,nPunishEndTime=%lu,nPunishReason=%d",
	    		nRoleID, nPlayerGender, nVipLevel, nMoney, nOnlineTime, nPunishType,
	    		nPunishEndTime, nPunishReason);
	    offset = (uint32_t)strlen(buf);
	    if(nRoomCount > 0)
	    {
	    	sprintf(buf + offset, "arrRoomID={");
	    	offset = (uint32_t)strlen(buf);

	    	int32_t i = 0;
	    	for(i = 0; i < nRoomCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrRoomID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}", arrRoomID[i]);
	    	offset = (uint32_t)strlen(buf);

	    	sprintf(buf + offset, ",arrRoleRank={");
			offset = (uint32_t) strlen(buf);


			 i = 0;

			for (i = 0; i < nRoomCount - 1; ++i) {
				sprintf(buf + offset, "%d, ", arrRoleRank[i]);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "%d}", arrRoleRank[i]);
			offset = (uint32_t) strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "arrRoomID={}");
	    	offset = (uint32_t)strlen(buf);
	    }
	    sprintf(buf + offset, ",nIdentityType=%d,nOnMicTime=%d",nIdentityType,nOnMicTime);
	    offset = (uint32_t)strlen(buf);
	    sprintf(buf + offset, ",nAccountID=%d,strRoleName=%s,nSelfSetting=%d,nLoginTimes=%d,nCollectCount=%d,arrCollectRoomList={",
	    		nAccountID,strRoleName.GetString(),nSelfSetting,nLoginTimes,nCollectCount);
	    offset = (uint32_t)strlen(buf);
	    for(uint16_t i = 0; i < nCollectCount; ++i)
	    {
		    sprintf(buf + offset, "%d, ", arrCollectRoomList[i]);
		    offset = (uint32_t)strlen(buf);
	    }
	    sprintf(buf + offset, "}}");
	    offset = (uint32_t)strlen(buf);
	}
public:
	CGetRoleInfoResp_Public()
	{
		nResult = 0;
		nRoleID = enmInvalidRoleID;
		nPlayerGender = enmGender_Unknown;
		nVipLevel = enmVipLevel_NONE;
		nMoney = 0;
		nOnlineTime = 0;
		nPunishType = enmInvalidPunishType;
		nPunishEndTime = 0;
		nPunishReason = enmInvalidPunishReason;
		nRoomCount = 0;
		for(int32_t i =0;i<MaxBeAdminPerPlayer;i++)
		{
			arrRoomID[i] = enmInvalidRoomID;
			arrRoleRank[i] = enmRoleRank_None;
		}
		nIdentityType = enmIdentityType_None;
		nOnMicTime = 0;
		nAccountID = 0;
		strRoleName = "";
		nSelfSetting = 0;
		nLoginTimes = 0;
		nCollectCount = 0;
	}

	int32_t			nResult;
	RoleID			nRoleID;
	Gender			nPlayerGender;
	VipLevel		nVipLevel;							//vip�ȼ�
	uint32_t		nMoney;
	uint32_t		nOnlineTime;						//�ܹ�����ʱ��
	PunishType		nPunishType;						//��������
	uint64_t		nPunishEndTime;						//������ֹʱ��
	PunishReason	nPunishReason;						//����ԭ��
	uint16_t		nRoomCount;
	RoomID			arrRoomID[MaxBeAdminPerPlayer];		//��������
	RoleRank		arrRoleRank[MaxBeAdminPerPlayer];
	IdentityType    nIdentityType;                      //���
	uint32_t		nOnMicTime;						//�ܹ�������ʱ��
	uint32_t 		nAccountID;   //179ID
	CString<MaxRoleNameLength> 	strRoleName; //����ǳ�
	uint32_t		nSelfSetting;            //��ҵĸ�������
	uint32_t		nLoginTimes;	    	 //��¼����
	uint16_t		nCollectCount;			//�ղط������
	RoomID			arrCollectRoomList[MaxCollectCount];	//�ղط����б�

};

//��ȡ������Ϣ����
#define MSGID_RSDB_GETROOMINFO_REQ		0x00110702
class CGetRoomInfoReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoomID=%d}", nRoomID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	CGetRoomInfoReq_Public()
	{
		nRoomID = enmInvalidRoomID;
	}
	RoomID			nRoomID;
};


//��ȡ������Ϣ��Ӧ
#define MSGID_DBRS_GETROOMINFO_RESP		0x00120702
class CGetRoomInfoResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult<0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRegionType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRegionID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRegionName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strChannelName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomFund);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomOption);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMicroTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMaxShowUserLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMaxRealUserLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nHostGender);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nHost179ID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strPassword.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCurMemberCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nCurMemberCount>MaxAdminCountPerRoom)
		{
			return ENCODE_DECODE_FILED;
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleRank[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrTotalTime[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrMicTime[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = strRoomNotice.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomSignature.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomWelcome.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nInBlackPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nInBlackPlayerCount>MaxRoomBlackListSize)
		{
			return ENCODE_DECODE_FILED;
		}
		for(uint32_t i = 0; i < nInBlackPlayerCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrBlackRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTimeLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTimeUnLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strLockReason.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRobotPercent);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSendPercent);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult<0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRegionType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRegionID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRegionName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strChannelName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomFund);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomOption);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMicroTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMaxShowUserLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMaxRealUserLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nHostGender);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nHost179ID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strPassword.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCurMemberCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nCurMemberCount>MaxAdminCountPerRoom)
		{
			return ENCODE_DECODE_FILED;
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleRank[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrTotalTime[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nCurMemberCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrMicTime[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = strRoomNotice.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomSignature.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomWelcome.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nInBlackPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nInBlackPlayerCount>MaxRoomBlackListSize)
		{
			return ENCODE_DECODE_FILED;
		}
		for(uint32_t i = 0; i < nInBlackPlayerCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrBlackRoleID[i]);
			if (0 > nRet)
		{
				return nRet;
			}
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTimeLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTimeUnLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strLockReason.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRobotPercent);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSendPercent);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nResult=%d,nRegionType=%d,nRegionID=%d,strRegionName=%s,nChannelType=%d,"
	    		"nChannelID=%d,strChannelName=%s,nRoomType=%d,nRoomID=%d"
	    		"strRoomName=%s,nRoomFund=%d,nRoomOption=%d,nMicroTime=%d,nMaxShowUserLimit=%d,"
	    		"nMaxRealUserLimit=%d,nHostID=%d,strHostName=%s,nHostGender=%d,nHost179ID=%d,strPassword=%s,nCurMemberCount=%d,",
	    		nResult,nRegionType, nRegionID, strRegionName.GetString(), nChannelType,
	    		nChannelID, strChannelName.GetString(), nRoomType, nRoomID,
	    		strRoomName.GetString(), nRoomFund, nRoomOption, nMicroTime, nMaxShowUserLimit,
	    		nMaxRealUserLimit, nHostID, strHostName.GetString(),nHostGender,nHost179ID, strPassword.GetString(), nCurMemberCount);
	    offset = (uint32_t)strlen(buf);
	    if(nCurMemberCount > 0)
	    {
	    	sprintf(buf + offset, "arrRoleID={");
	    	offset = (uint32_t)strlen(buf);

	    	int32_t i = 0;
	    	for(i = 0; i < nCurMemberCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrRoleID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrRoleRank={", arrRoleID[i]);
	    	offset = (uint32_t)strlen(buf);

	    	i = 0;
	    	for(i = 0; i < nCurMemberCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrRoleRank[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrTotalTime={", arrRoleRank[i]);
	    	offset = (uint32_t)strlen(buf);

	    	i = 0;
	    	for(i = 0; i < nCurMemberCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrTotalTime[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}}", arrTotalTime[i]);
	    	offset = (uint32_t)strlen(buf);
	    	i = 0;
			for (i = 0; i < nCurMemberCount - 1; ++i) {
				sprintf(buf + offset, "%d, ", arrMicTime[i]);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "%d}}", arrMicTime[i]);
			offset = (uint32_t) strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "arrRoleID={},arrRoleRank={},arrTotalTime={}");
	    	offset = (uint32_t)strlen(buf);
	    }
	    sprintf(buf + offset, "strRoomNotice=%s,strRoomSignature=%s,strRoomWelcome=%s",strRoomNotice.GetString(),strRoomSignature.GetString(),strRoomWelcome.GetString());
	    offset = (uint32_t)strlen(buf);
	    sprintf(buf + offset, "nInBlackPlayerCount=%d,arrBlackRoleID={",nInBlackPlayerCount);
	    offset = (uint32_t)strlen(buf);
	    for(uint32_t i = 0;i<nInBlackPlayerCount;i++)
	    {
	    	 sprintf(buf + offset, "%d",arrBlackRoleID[i]);
	    	offset = (uint32_t)strlen(buf);
	    	if(i+1!=nInBlackPlayerCount)
	    	{
	    		sprintf(buf + offset, ",");
	    		offset = (uint32_t)strlen(buf);
	    	}
	    }
	    sprintf(buf + offset, "}");
	    offset = (uint32_t)strlen(buf);

	    sprintf(buf + offset, "nTimeLock=%d,nTimeUnLock=%d,strLockReason=%s",nTimeLock,nTimeUnLock,strLockReason.GetString());
	    offset = (uint32_t)strlen(buf);
	    sprintf(buf + offset, ",nRobotPercent=%d,nSendPercent=%d}}",nRobotPercent,nSendPercent);
	   	offset = (uint32_t)strlen(buf);
	}
public:
	CGetRoomInfoResp_Public()
	{
		nResult = 0; //��ӦС��0ʱΪ���ɹ�
		nRegionType = enmInvalidRegionType;
		nRegionID = enmInvalidRegionID;
		strRegionName = "";
		nChannelType = enmInvalidChannelType;
		nChannelID = enmInvalidChannelID;
		strChannelName = "";
		nRoomType = enmInvalidRoomType;
		nRoomID = enmInvalidRoomID;
		strRoomName = "";
		nRoomFund = 0;
		nRoomOption = 0;
		nMicroTime = 0; //��������֮һ���ڸ÷�������ϲ��ܳ����೤ʱ�䣬����30����
		nMaxShowUserLimit = 0; //С�ĸ���ֵ
		nMaxRealUserLimit = 0; //��ĸ���ֵ
		nHostID = enmInvalidRoleID;
		strHostName = "";
		nHostGender = 0; //�����Ա�
		nHost179ID = 0; //����179ID
		strPassword = "";
		nCurMemberCount = 0;
		memset(arrRoleID, 0, sizeof(arrRoleID));
		memset(arrRoleRank, 0, sizeof(arrRoleRank));
		memset(arrTotalTime, 0, sizeof(arrTotalTime));
		memset(arrMicTime, 0, sizeof(arrMicTime));
		strRoomNotice = ""; //����Ĺ���
		strRoomSignature = ""; //���������
		strRoomWelcome = ""; //����Ļ�ӭ��
		nInBlackPlayerCount = 0; //�ں������е����
		memset(arrBlackRoleID, 0, sizeof(arrBlackRoleID));
		nTimeLock = 0;//������ʼʱ��
		nTimeUnLock = 0;//����ʱ��
		strLockReason = "";
		nRobotPercent = 0; //�����˸���/���˸�����100
		nSendPercent = 0; //���Ͳ����ĸ���
	}
	int32_t			                    nResult; //��ӦС��0ʱΪ���ɹ�
	RegionType							nRegionType;
	RegionID							nRegionID;
	CString<MaxRegionNameLength>		strRegionName;
	ChannelType							nChannelType;
	ChannelID							nChannelID;
	CString<MaxChannelNameLength>		strChannelName;
	RoomType							nRoomType;
	RoomID								nRoomID;
	CString<MaxRoomNameLength>			strRoomName;

	uint32_t							nRoomFund;
	uint32_t							nRoomOption;
	uint32_t							nMicroTime;       //��������֮һ���ڸ÷�������ϲ��ܳ����೤ʱ�䣬����30����

	uint16_t							nMaxShowUserLimit; //С�ĸ���ֵ
	uint16_t							nMaxRealUserLimit; //��ĸ���ֵ

	RoleID								nHostID;
	CString<enmMaxRoleNameLength>		strHostName;
	Gender 								nHostGender; //�����Ա�
	uint32_t 							nHost179ID;   //����179ID

	CString<MaxRoomPasswordLength> 		strPassword;

	uint16_t							nCurMemberCount;
	RoleID								arrRoleID[MaxAdminCountPerRoom];
	RoleRank							arrRoleRank[MaxAdminCountPerRoom];
	uint32_t							arrTotalTime[MaxAdminCountPerRoom];//�ڷ��������ʱ��
	uint32_t							arrMicTime[MaxAdminCountPerRoom];//�ڷ��������ʱ��
	CString<MaxRoomNoticeLength> 		strRoomNotice; //����Ĺ���
	CString<MaxRoomSignatureLength> 	strRoomSignature; //���������
	CString<MaxRoomWelcomeLength> 		strRoomWelcome; //����Ļ�ӭ��
	uint32_t                            nInBlackPlayerCount; //�ں������е����
	RoleID								arrBlackRoleID[MaxRoomBlackListSize];
	uint32_t 						    nTimeLock;//������ʼʱ��
	uint32_t 						    nTimeUnLock;//����ʱ��
	CString<MaxTextMessageSize> 	    strLockReason; //����ԭ��
	uint32_t							nRobotPercent;		//�����˸���/���˸�����100
	uint32_t							nSendPercent;			//���Ͳ����ĸ���
};

//�����Ҫת�����ݵ�user
#define MSGID_RSMS_ADD_TRANSMITUSER_NOTI			0x00130703
class CAddTransmitUserNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:

	int32_t MessageEncode( uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Encode(buf, size, offset, nAddCount);
		if (0 > nRet)
		{
			return nRet;
		}

		if (MaxTransmitUserCount < nAddCount)
		{
			return E_INVALIDARGUMENT;
		}
		for (uint32_t i = 0; i < nAddCount && i < MaxTransmitUserCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrAddRoleID[i]);
			if (nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;

	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nAddCount);
		if (0 > nRet)
		{
			return nRet;
		}

		if (MaxTransmitUserCount < nAddCount)
		{
			return E_INVALIDARGUMENT;
		}
		for (uint32_t i = 0; i < nAddCount && i < MaxTransmitUserCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrAddRoleID[i]);
			if (nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;

	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(
				buf + offset,
				"{nUserStatus=%d, nRoleID=%d, nRoomID=%d, nAddCount=%d,arrAddRoleID={",
				nUserStatus, nRoleID, nRoomID, nAddCount);
		offset = (uint32_t) strlen(buf);
		for (uint32_t i = 0; i < nAddCount && i < MaxTransmitUserCount; ++i) {
			sprintf(buf + offset, "%d", arrAddRoleID[i]);
			offset = (uint32_t) strlen(buf);
			if (i < nAddCount - 1) {
				sprintf(buf + offset, ", ");
				offset = (uint32_t) strlen(buf);
			}
		}
		offset = (uint32_t) strlen(buf);
		sprintf(buf + offset, "}}");
		offset = (uint32_t) strlen(buf);
	}
public:
	CAddTransmitUserNotice_Public()
	{
		nUserStatus = 0;
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
		nAddCount = 0;
		for(int32_t i =0;i<MaxTransmitUserCount;i++)
		{
			arrAddRoleID[i] = enmInvalidRoleID;
		}
	}
	UserStatus nUserStatus;
	RoleID nRoleID;
	RoomID nRoomID;
	uint32_t nAddCount;
	RoleID arrAddRoleID[MaxTransmitUserCount];
};

//ɾ����Ҫת�����ݵ�user
#define MSGID_RSMS_DELETE_TRANSMITUSER_NOTI			0x00130704
class CDelTransmitUserNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode( uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Encode(buf, size, offset, nDelCount);
		if (0 > nRet)
		{
			return nRet;
		}

		if (MaxTransmitUserCount < nDelCount)
		{
			return E_INVALIDARGUMENT;
		}
		for (uint32_t i = 0; i < nDelCount && i < MaxTransmitUserCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrDelRoleID[i]);
			if (nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;

	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nDelCount);
		if (0 > nRet)
		{
			return nRet;
		}

		if (MaxTransmitUserCount < nDelCount)
		{
			return E_INVALIDARGUMENT;
		}
		for (uint32_t i = 0; i < nDelCount && i < MaxTransmitUserCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrDelRoleID[i]);
			if (nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(
				buf + offset,
				"{nUserStatus=%d, nRoleID=%d, nRoomID=%d, nDelCount=%d,arrDelRoleID={",
				nUserStatus, nRoleID, nRoomID, nDelCount);
		offset = (uint32_t) strlen(buf);
		for (uint32_t i = 0; i < nDelCount && i < MaxTransmitUserCount; ++i) {
			sprintf(buf + offset, "%d", arrDelRoleID[i]);
			offset = (uint32_t) strlen(buf);
			if (i < nDelCount - 1) {
				sprintf(buf + offset, ", ");
				offset = (uint32_t) strlen(buf);
			}
		}
		offset = (uint32_t) strlen(buf);
		sprintf(buf + offset, "}}");
		offset = (uint32_t) strlen(buf);
	}
public:
	CDelTransmitUserNotice_Public()
	{
		nUserStatus = 0;
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
		nDelCount = 0;
		for (int32_t i = 0; i < MaxTransmitUserCount; i++)
		{
			arrDelRoleID[i] = enmInvalidRoleID;
		}
	}
	UserStatus nUserStatus;
	RoleID nRoleID;
	RoomID nRoomID;
	uint32_t nDelCount;
	RoleID arrDelRoleID[MaxTransmitUserCount];
};

//�޸�����Ƶת��
#define MSGID_RSMS_MODIFY_TRANSMIT_NOTI			0x00130705

class CModifyMediaNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:

	int32_t MessageEncode( uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Encode(buf, size, offset, nModifyType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nModifyValue);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nModifyRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset,nUserStatus);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nModifyType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nModifyValue);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nModifyRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(
				buf + offset,
				"{nUserStatus=%d, nRoleID=%d, nRoomID=%d, nModifyType=%d, nModifyValue=%d, nModifyRoleID=%d}",
				nUserStatus, nRoleID, nRoomID, nModifyType, nModifyValue,
				nModifyRoleID);

		offset = (uint32_t) strlen(buf);
	}
public:
	CModifyMediaNotice_Public()
	{
		nUserStatus = 0;
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
		nModifyType = 0;
		nModifyValue = 0;
		nModifyRoleID = enmInvalidRoleID;
	}
	UserStatus nUserStatus;
	RoleID nRoleID;
	RoomID nRoomID;
	ModifyType nModifyType;
	ModifyValue nModifyValue;
	RoleID nModifyRoleID;
};


//��������֪ͨ
#define MSGID_RSMS_CREATE_ROOM_NOTICE			0x00130706
class CCreateRoomNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CCreateRoomNotice_Public()
	{
		nRegionType = enmInvalidRegionType;
		nRegionID = enmInvalidRegionID;
		strRegionName = "";
		nChannelType = enmInvalidChannelType;
		nChannelID = enmInvalidChannelID;
		strChannelName = "";
		nRoomType = enmInvalidRoomType;
		nRoomID = enmInvalidRoomID;
		strRoomName = "";
		nServerID = 0;
		nMemberCount = 0;
		memset(arrRoleID,0,sizeof(arrRoleID));
		memset(arrRoleRank,0,sizeof(arrRoleRank));
		nHostID = enmInvalidRoleID;
		strHostName = "";
	}
	RegionType nRegionType;
	RegionID nRegionID;
	CString<MaxRegionNameLength> strRegionName;
	ChannelType nChannelType;
	ChannelID nChannelID;
	CString<MaxChannelNameLength> strChannelName;
	RoomType nRoomType;
	RoomID nRoomID;
	CString<MaxRoomNameLength> strRoomName;
	ServerID nServerID;
	int32_t nMemberCount;							//��Ա����
	RoleID arrRoleID[MaxAdminCountPerRoom];			//��Աroleid
	RoleRank arrRoleRank[MaxAdminCountPerRoom];		//��ԱȨ��
	RoleID	nHostID;
	CString<enmMaxRoleNameLength> strHostName;

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(buf + offset, "{nRegionType=%d,nRegionID=%d,strRegionName=%s,"
				"nChannelType=%d,nChannelID=%d,strChannelName=%s,nRoomType=%d,"
				"nRoomID=%d,strRoomName=%s,nServerID=%d,nMemberCount=%d,arrRoleID={",
				nRegionType,nRegionID,strRegionName.GetString(),nChannelType,nChannelID,
				strChannelName.GetString(),nRoomType,nRoomID,strRoomName.GetString(),nServerID,nMemberCount);
		offset = (uint32_t) strlen(buf);
		if(nMemberCount > 0)
		{
			for(int32_t i = 0; i < nMemberCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoleID[i]);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "%d},arrRoleRank={", arrRoleID[nMemberCount - 1]);
			offset = (uint32_t) strlen(buf);
			for(int32_t i = 0; i < nMemberCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoleRank[i]);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "%d}}", arrRoleRank[nMemberCount - 1]);
			offset = (uint32_t) strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "},arrRoleRank={}");
			offset = (uint32_t) strlen(buf);
		}
		 sprintf(buf + offset, ",nHostID=%d,strHostName=%s}",
			    		 nHostID, strHostName.GetString());
			    offset = (uint32_t)strlen(buf);
	}
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRegionType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRegionID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRegionName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strChannelName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMemberCount);
		if (0 > nRet) {
			return nRet;
		}
		if (nMemberCount > 0)
		{
			for (int32_t i = 0; i < nMemberCount; ++i)
			{
				nRet= CCodeEngine::Encode(buf, size, offset,arrRoleID[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			for (int32_t i = 0; i < nMemberCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset,arrRoleRank[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}
		return nRet;
	}

	int32_t	MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRegionType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRegionID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRegionName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strChannelName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoomName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMemberCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nMemberCount > 0)
		{
			for(int32_t i = 0; i < nMemberCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nMemberCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrRoleRank[i]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}
		return nRet;
	}
};

//���ٷ���֪ͨ
#define MSGID_RSMS_DESTORY_ROOM_NOTICE			0x00130707
class CDestoryRoomNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDestoryRoomNotice_Public()
	{
		nRoomID = enmInvalidRoomID;
		nServerID = 0;
	}
	RoomID nRoomID;
	ServerID nServerID;

public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t &offset)
	{

		int32_t nRet = S_OK;

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

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

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
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(buf + offset, "{nRoomID=%d, nServerID=%d}", nRoomID, nServerID);
		offset = (uint32_t) strlen(buf);
	}
};

//���뷿��֪ͨ
#define MSGID_RSMS_ENTER_ROOM_NOTICE			0x00130708
class CEnterRoomNotice_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CEnterRoomNotice_Public()
	{
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
		nServerID = 0;
		nPlayerType = enmPlayerType_Normal;
		nRoleRank = enmRoleRank_None;
		strRoleName = "";
		nAccountID = 0;
		nRoomType = enmInvalidRoomType;
		nIdentityType = enmIdentityType_None;
		nKey = 0;
		nEnterRoomType = enmEnterRoomType_Normal;
	}
	RoleID 						nRoleID;
	RoomID 						nRoomID;
	ServerID 					nServerID;
	PlayerType 					nPlayerType;//�ǻ����ˣ���������
	RoleRank 					nRoleRank;
	CString<MaxRoleNameLength> 	strRoleName; //����ǳ�
	AccountID 					nAccountID;   //179ID
	RoomType					nRoomType;	  //����ķ�������
	IdentityType				nIdentityType; //�������˵����
	uint32_t 					nKey;
	EnterRoomType				nEnterRoomType;


public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(buf + offset, "{nRoleID=%d, nRoomID=%d,nServerID=%d,nPlayerType=%d,nRoleRank=%d,strRoleName=%s,179ID=%u,nRoomType=%d,nIdentityType=%d, nKey=%d,nEnterRoomType=%d}", nRoleID, nRoomID, nServerID, nPlayerType, nRoleRank,strRoleName.GetString(),nAccountID,nRoomType,nIdentityType,nKey,nEnterRoomType);
		offset = (uint32_t) strlen(buf);
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
		nRet = CCodeEngine::Encode(buf, size, offset, nServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nAccountID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nKey);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEnterRoomType);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nAccountID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nKey);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEnterRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

};


//�˳�����֪ͨ
#define MSGID_RSMS_EXIT_ROOM_NOTICE			0x00130709
class CExitRoomNotice_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CExitRoomNotice_Public()
	{
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
		nRoomType = enmInvalidRoomType;
	}
	RoleID 						nRoleID;
	RoomID 						nRoomID;
	RoomType					nRoomType;	  //�˳��ķ�������

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset) {
		sprintf(buf + offset, "{nRoleID=%d, nRoomID=%d, nRoomType=%d}", nRoleID, nRoomID,nRoomType);
		offset = (uint32_t) strlen(buf);
	}
	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
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
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomType);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomType);
		if (0 > nRet)
		{
			return nRet;
		}
		return nRet;
	}
};

#define MSGID_RSHS_UPDATEINFOTOHALL_NOTICE		0x0013070a
class CUpdateInfoToHallNotice_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateInfoToHallNotice_Public()
	{
		nRoomCount = 0;
		memset(arrRoomID,0,sizeof(arrRoomID));
		memset(arrPlayerCount,0,sizeof(arrPlayerCount));
		for(int32_t i =0;i<MaxRoomCountPerServer;i++)
		{
			memset(arrRoleID[i],0,sizeof(arrRoleID[i]));
		}
		nServerAddress = 0;
		nServerPort = 0;
		nServerNetType = enmNetType_Tel;
		nRecvPacketsPerTenMins =0;
		nPartServerID = 0;
	}
	int32_t		nRoomCount;
	RoomID		arrRoomID[MaxRoomCountPerServer];
	int32_t		arrPlayerCount[MaxRoomCountPerServer];
	RoleID		arrRoleID[MaxRoomCountPerServer][MaxUserCountPerRoom];
	uint32_t	nServerAddress;
	uint16_t	nServerPort;
	NetType		nServerNetType;
	int32_t		nRecvPacketsPerTenMins;//mediaserver�10���ӷ��͵�upd���������ȣ�
	ServerID	nPartServerID;	//media��partsever��ID

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{

		sprintf(buf + offset, "{ nRoomCount=%d, arrRoom={",
				 nRoomCount);

		offset = (uint32_t) strlen(buf);
		for (int32_t i = 0; i < nRoomCount; ++i) {
			sprintf(buf + offset,
					"RoomID=%d,PlayerCount=%d, arrRoleID={",
					arrRoomID[i], arrPlayerCount[i]);
			offset = (uint32_t) strlen(buf);
			for (int32_t j = 0; j < arrPlayerCount[i]; ++j) {
				sprintf(buf + offset, "%d", arrRoleID[i][j]);
				offset = (uint32_t) strlen(buf);
				if (j < arrPlayerCount[i] - 1) {
					sprintf(buf + offset, ",");
				}
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "}");
			offset = (uint32_t) strlen(buf);
			if (i < nRoomCount - 1) {
				sprintf(buf + offset, ",");
			}
			offset = (uint32_t) strlen(buf);
		}

		sprintf(buf + offset, "}, nServerAddress=%s, nServerPort=%d,nServerNetType=%d,nRecvPacketsPerTenMins=%d}",
				inet_ntoa_f(nServerAddress), nServerPort,nServerNetType, nRecvPacketsPerTenMins);

		offset = (uint32_t) strlen(buf);
	}

	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomCount);
		if (0 > nRet)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoomID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrPlayerCount[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			for(int32_t j = 0; j < arrPlayerCount[i]; ++j)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i][j]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nServerAddress);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nServerPort);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nServerNetType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRecvPacketsPerTenMins);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPartServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomCount);
		if (0 > nRet)
		{
			return nRet;
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoomID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrPlayerCount[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		for(int32_t i = 0; i < nRoomCount; ++i)
		{
			for(int32_t j = 0; j < arrPlayerCount[i]; ++j)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i][j]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nServerAddress);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nServerPort);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nServerNetType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRecvPacketsPerTenMins);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPartServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
};

#define MSGID_RSHS_GETMEDIAINFO_REQ				0x0011070b
class CGetMediaInfoReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nothing}");
		offset = (uint32_t) strlen(buf);
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
};

#define MSGID_HSRS_GETMEIDAINFO_RESP			0x0012070b
class CGetMediaInfoResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetMediaInfoResp_Public()
	{
		nResult = 0;
		nTelMediaIP = 0;
		nTelMediaPort = 0;
		nTelServerID = enmInvalidServerID;
		nCncMediaIP = 0;
		nCncMediaPort = 0;
		nCncServerID  = enmInvalidServerID;
	}
	int32_t		nResult;
	uint32_t	nTelMediaIP;
	uint16_t	nTelMediaPort;
	ServerID    nTelServerID;  //����media��ID
	uint32_t	nCncMediaIP;
	uint16_t	nCncMediaPort;
	ServerID    nCncServerID;  //��ͨmedia��ID

public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nTelMediaIp=%s, nTelMediaPort=%d,nTelServerID=%d, ", inet_ntoa_f(nTelMediaIP), nTelMediaPort,nTelServerID);
		offset = (uint32_t) strlen(buf);
		sprintf(buf + offset, "nCncMediaIp=%s, nCncMediaPort=%d,nCncServerID=%d}", inet_ntoa_f(nCncMediaIP), nCncMediaPort,nCncServerID);
		offset = (uint32_t) strlen(buf);
	}

	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}

		if(nResult < 0)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nTelMediaIP);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTelMediaPort);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTelServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncMediaIP);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncMediaPort);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCncServerID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}

	int32_t	MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}

		if(nResult < 0)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nTelMediaIP);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTelMediaPort);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTelServerID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncMediaIP);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncMediaPort);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCncServerID);
		if (0 > nRet)
		{
			return nRet;
		}

		return nRet;
	}
};
#define MSGID_RSHS_GET_ROLE_GLOBALINFO_REQ				0x0011070c
class CGetRoleGlobalInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	 int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	 int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nothing}");
		offset = (uint32_t) strlen(buf);
	}
};

#define MSGID_HSRS_GET_ROLE_GLOBALINFO_RESP			0x0012070c
class CGetRoleGlobalInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetRoleGlobalInfoResp()
	{
		nResult = 0;
		nEnterCount = 0;
		nPlayerState = enmInvalidPlayerState;
		nEnterNewPlayerRoomCount = 0;
	}
	int32_t			nResult;
	uint32_t		nEnterCount;//���뷿�������
	PlayerState 	nPlayerState;//��ҵ�״̬
	uint32_t		nEnterNewPlayerRoomCount; //��������ַ�������

	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset) {
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet) {
			return nRet;
		}
		if(nResult<0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEnterCount);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerState);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEnterNewPlayerRoomCount);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size,
			uint32_t& offset) {
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet) {
			return nRet;
		}
		if(nResult<0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEnterCount);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerState);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEnterNewPlayerRoomCount);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}
public:
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nEnterCount=%d,nPlayerState=%d,nEnterNewPlayerRoomCount=%d}", nResult, nEnterCount,nPlayerState,nEnterNewPlayerRoomCount);
		offset = (uint32_t) strlen(buf);
	}
};
//���ù���Ա��Ӧ
#define MSGID_DBRS_SET_TITLE_RESP		0x0012070e
class CSetTitleResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetTitleResp_Public()
	{
		nResult = 0;
	}
	int32_t	nResult; //>=0Ϊ�ɹ���<0Ϊʧ��
public:

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d",nResult);
		offset = (uint32_t) strlen(buf);
	}
};

//���ù���Ա����
#define MSGID_RSDB_SET_TITLE_REQ		0x0011070e
class CSetTitleReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetTitleReq_Public()
	{
		nRoleID = enmInvalidRoleID;
		nRoleRank = enmRoleRank_None;
	}
	RoleID nRoleID;
	RoleRank nRoleRank;

public:
	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRoleRank);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d,nRoleRank=%d",nRoleID,nRoleRank);
		offset = (uint32_t) strlen(buf);
	}
};

//ɾ������Ա��Ӧ
#define MSGID_DBRS_DEL_TITLE_RESP		0x00120710
class CDelTitleResp_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDelTitleResp_Public()
	{
		nResult = 0;
	}
	int32_t	nResult;  //>=0Ϊ�ɹ���<0Ϊʧ��
public:
	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d",nResult);
		offset = (uint32_t) strlen(buf);
	}
};
//ɾ������Ա����
#define MSGID_RSDB_DEL_TITLE_REQ		0x00110710
class CDelTitleReq_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDelTitleReq_Public()
	{
		nRoleID = enmInvalidRoleID;
	}
	RoleID nRoleID;

public:
	int32_t MessageDecode(uint8_t *buf, const uint32_t size, uint32_t& offset)
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

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d",nRoleID);
		offset = (uint32_t) strlen(buf);
	}
};

//���÷������Ի�Ӧ
#define MSGID_DBRS_SET_ROOM_RESP		0x00120711
class CSetRoomAttrResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetRoomAttrResp()
	{
		nResult = 0;
	}
	int32_t	nResult;  //>=0Ϊ�ɹ���<0Ϊʧ��
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}",
				nResult);
		offset = (uint32_t)strlen(buf);
	}
};
//���÷�������
#define MSGID_RSDB_SET_ROOM_REQ		0x00110711
class CSetRoomAttrReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetRoomAttrReq()
	{
		nSetCount = 0;
		memset(arrRoomInfoType,0,sizeof(arrRoomInfoType));
		nStringCount = 0;
		for(int32_t i = 0;i<MaxSetRoomTypeCount;i++)
		{
			arrSetString[i] = "";
		}
		nMicTime = 0;
		nRoomOptionType = 0;
	}
	uint8_t							nSetCount;                             //�޸ĸ���
	RoomInfoType 					arrRoomInfoType[MaxSetRoomTypeCount];  //�޸���������
	uint8_t							nStringCount;                          //��Ҫ�޸ĵ����ַ������͵ĸ���
	CString<MaxSetRoomTextSize> 	arrSetString[MaxSetRoomTypeCount];     //Ҫ�޸ĵ��ַ�����
	uint32_t	                    nMicTime;							   //�޸�ʱ�䣨arrRoomInfoType ������Ҫ�޸�ʱ��ʱ�����壩
	RoomOptionType                  nRoomOptionType;					   //�޸�Option��arrRoomInfoType ������Ҫ�޸�Optionʱ�����壩

public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nSetCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nSetCount>MaxSetRoomTypeCount)
		{
			return ENCODE_DECODE_FILED;
		}
		uint8_t nStringCountTemp = nStringCount;
		for(int32_t i = 0;i<nSetCount;i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoomInfoType[i]);
			if (nRet < 0)
			{
				return nRet;
			}
			switch (arrRoomInfoType[i])
			{
				case enmRoomInfoType_FREESHOW_TIME:
				{
					nRet = CCodeEngine::Encode(buf, size, offset, nMicTime);
					if (nRet < 0)
					{
						return nRet;
					}
				}
				break;
				case enmRoomInfoType_OPTION:
				{

					nRet = CCodeEngine::Encode(buf, size, offset, nRoomOptionType);
					if (nRet < 0)
					{
						return nRet;
					}
				}
				break;
				default:
				{
					nRet = arrSetString[nStringCount-nStringCountTemp].MessageEncode(buf, size, offset);
					if (0 > nRet)
					{
						return nRet;
					}
					nStringCountTemp--;
				}
				break;
			}
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nSetCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nSetCount>MaxSetRoomTypeCount)
		{
			return ENCODE_DECODE_FILED;
		}
		nStringCount = 0;
		for(int32_t i = 0;i<nSetCount;i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoomInfoType[i]);
			if (nRet < 0)
			{
				return nRet;
			}
			switch (arrRoomInfoType[i])
			{
				case enmRoomInfoType_FREESHOW_TIME:
				{
					nRet = CCodeEngine::Decode(buf, size, offset, nMicTime);
					if (nRet < 0)
					{
						return nRet;
					}
				}
				break;
				case enmRoomInfoType_OPTION:
				{

					nRet = CCodeEngine::Decode(buf, size, offset, nRoomOptionType);
					if (nRet < 0)
					{
						return nRet;
					}
				}
				break;
				default:
				{
					nRet = arrSetString[nStringCount].MessageDecode(buf, size, offset);
					if (0 > nRet)
					{
						return nRet;
					}
					nStringCount++;
				}
				break;
			}
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nSetCount=%d,arrRoomInfoType={",nSetCount );
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0;i<nSetCount;i++)
		{
			sprintf(buf + offset, "%d",arrRoomInfoType[i]);
			offset = (uint32_t)strlen(buf);
			if(i+1<nSetCount)
			{
				sprintf(buf + offset, ",");
			}
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
};
#define MSGID_RSDB_ADD_ONLINE_TIME_INROOM_NOTICE		0x00130712
class CAddAdmInRoomOnLineTimeNotice : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CAddAdmInRoomOnLineTimeNotice()
	{
		nYear = 0;
		nMonth = 0;
		nDay = 0;
		nRoleID = 0;
		nRoomID = 0;
		nAddTime = 0;
		nRoleRank = enmRoleRank_None;
	}
	uint16_t nYear;
	uint16_t nMonth;
	uint16_t nDay;
	RoleID nRoleID;   //��������
	RoomID nRoomID;   //�����ķ���
	uint32_t nAddTime; //ʱ�������
    RoleRank nRoleRank;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nYear);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMonth);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nDay);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet) {
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (nRet < 0) {
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nAddTime);
		if (nRet < 0) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleRank);
		if (nRet < 0) {
			return nRet;
		}
        return  nRet;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nYear);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMonth);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nDay);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (nRet < 0) {
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nAddTime);
		if (nRet < 0) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (nRet < 0) {
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nYear=%d,nMonth=%d,nDay=%d,nRoleID=%d,nRoomID=%d,nAddTime=%d,nRoleRank=%d",nYear,nMonth,nDay,nRoleID,nRoomID, nAddTime,nRoleRank);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSDB_ADD_ONMIC_TIME_INROOM_NOTICE		0x00130713
class CAddOnMicTimeNotice : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CAddOnMicTimeNotice()
	{
		nYear = 0;
		nMonth = 0;
		nDay = 0;
		nRoleID = 0;
		nRoomID = 0;
		nAddTime = 0;
	}
	uint16_t nYear;
	uint16_t nMonth;
	uint16_t nDay;
	RoleID nRoleID;   //��������
	RoomID nRoomID;   //�����ķ���
	uint32_t nAddTime; //ʱ�������(��Ҫ���������ط����ڷ���ġ��ܵ�)

public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nYear);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMonth);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nDay);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet) {
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (nRet < 0) {
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nAddTime);
		if (nRet < 0) {
			return nRet;
		}
        return  nRet;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nYear);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMonth);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nDay);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet) {
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (nRet < 0) {
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nAddTime);
		if (nRet < 0) {
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nYear=%d,nMonth=%d,nDay=%d,nRoleID=%d,nRoomID=%d,nAddTime=%d",nYear,nMonth,nDay,nRoleID,nRoomID, nAddTime);
		offset = (uint32_t)strlen(buf);
	}
};

class PlayerItemInfo
{
public:
	RoleID 			nRoleID;   //��ҵ�ID
	uint16_t		nItemCount;   //���ڱ�ʹ�õ���Ʒ����
	ItemID          arrItemID[MaxOnUserItemCount];
	PlayerItemInfo()
	{
		Reset();
	}
	void Reset()
	{
		nRoleID = enmInvalidRoleID;
		nItemCount = 0;
		for(uint32_t i =0;i<MaxOnUserItemCount;i++ )
		{
			arrItemID[i] = enmInvalidItemID;
		}
	}
};
//��itemsetver��õ�����Ϣ����
#define MSGID_RSIS_GET_ITEMINFO_REQ		0x00110714
class CGetItemInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetItemInfoReq()
	{
		nRoleID = enmInvalidRoleID;
	}
	RoleID nRoleID;//roleIDΪ0���ѯ�������������˵ġ�

public:
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

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d",nRoleID );
		offset = (uint32_t)strlen(buf);
	}
};

//��itemsetver��õ�����Ϣ��Ӧ
#define MSGID_ISRS_GET_ITEMINFO_RESP		0x00120714
class CGetItemInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetItemInfoResp()
	{
		nResult = 0;
		nPlayerCount = 0;
		memset(arrMagnateLevel,0,sizeof(arrMagnateLevel));
	}
	int32_t nResult;
	uint32_t nPlayerCount; //�ڷ��������
	PlayerItemInfo arrPlayerItemInfo[MaxUserCountPerRoom];//player�ĵ��߻�����Ϣ
	MagnateLevel arrMagnateLevel[MaxUserCountPerRoom];    //��ҵĲƸ��ȼ�
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet) {
			return nRet;
		}

		if(nResult<0)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}

		if(nPlayerCount>MaxUserCountPerRoom)
		{
			return ENCODE_DECODE_FILED;
		}
		for(uint32_t i = 0;i < nPlayerCount;i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrPlayerItemInfo[i].nRoleID);
			if (0 > nRet) {
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,arrPlayerItemInfo[i].nItemCount);
			if (0 > nRet) {
				return nRet;
			}
			if((uint16_t)MaxOnUserItemCount<arrPlayerItemInfo[i].nItemCount)
			{
				return ENCODE_DECODE_FILED;
			}
			for(uint32_t j =0 ;j<arrPlayerItemInfo[i].nItemCount;j++)
			{
				nRet = CCodeEngine::Encode(buf, size, offset,arrPlayerItemInfo[i].arrItemID[j]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			nRet = CCodeEngine::Encode(buf, size, offset,arrMagnateLevel[i]);
			if (0 > nRet)
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
		if (0 > nRet) {
			return nRet;
		}

		if (nResult < 0) {
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}
		if ( nPlayerCount > MaxUserCountPerRoom)
		{
			return ENCODE_DECODE_FILED;
		}
		for (uint32_t i = 0; i < nPlayerCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,arrPlayerItemInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,arrPlayerItemInfo[i].nItemCount);
			if (0 > nRet)
			{
				return nRet;
			}
			if ((uint16_t)MaxOnUserItemCount<arrPlayerItemInfo[i].nItemCount  )
			{
				return ENCODE_DECODE_FILED;
			}
			for (uint32_t j = 0; j < arrPlayerItemInfo[i].nItemCount; j++)
			{
				nRet = CCodeEngine::Decode(buf, size, offset,arrPlayerItemInfo[i].arrItemID[j]);
				if (0 > nRet)
				{
					return nRet;
				}
			}
			nRet = CCodeEngine::Decode(buf, size, offset,arrMagnateLevel[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d",nResult );
		offset = (uint32_t)strlen(buf);
		if(nResult<0)
		{
			return;
		}
		sprintf(buf + offset, ",nPlayerCount=%d,arrPlayerItemInfo={",nPlayerCount );
		offset = (uint32_t)strlen(buf);
/*		for(uint32_t i = 0 ;i<nPlayerCount;i++)
		{
			sprintf(buf + offset, "nRoleID=%d,nItemCount=%d,arrItemID={",arrPlayerItemInfo[i].nRoleID,arrPlayerItemInfo[i].nItemCount);
			offset = (uint32_t)strlen(buf);
			for(uint32_t j =0;j<arrPlayerItemInfo[i].nItemCount;j++)
			{
				sprintf(buf + offset, "0x%04x",arrPlayerItemInfo[i].arrItemID[j]);
				offset = (uint32_t)strlen(buf);
				if(j+1!=arrPlayerItemInfo[i].nItemCount)
				{
					sprintf(buf + offset, ",");
					offset = (uint32_t)strlen(buf);
				}
			}
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			if(i+1!=nPlayerCount)
			{
				sprintf(buf + offset, ",");
				offset = (uint32_t)strlen(buf);
			}
		}*/
		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}
};
#define MSGID_RSDB_ADD_BLACK_REQ		0x00110715
class CAddPlayerToBlackReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CAddPlayerToBlackReq()
	{
		nRoleID = enmInvalidRoleID;
		nRoomID = enmInvalidRoomID;
	}
	RoleID nRoleID;
	RoomID nRoomID;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
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
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d,nRoomID=%d",nRoleID,nRoomID );
		offset = (uint32_t)strlen(buf);
	}
};
#define MSGID_DBRS_ADD_BLACK_RESP		0x00120715
class CAddPlayerToBlackResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CAddPlayerToBlackResp()
	{
		nResult = 0;
	}
	int32_t nResult;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d",nResult);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSSS_LOCK_ROOM_NOTIFY		0x00130716
class CLockRoomToSysNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CLockRoomToSysNoti()
	{
		nRoomID = enmInvalidRoomID;
		nHostID = enmInvalidRoleID;
		strHostName = "";
		nTimeLock = 0;
		nTimeUnlock = 0;
		strLockRoomReason = "";
	}
	RoomID 											nRoomID;
	RoleID 											nHostID;
	CString<enmMaxRoleNameLength> 					strHostName; //�������ǳ�
	uint64_t 										nTimeLock;//����Ŀ�ʼʱ��
	uint64_t 										nTimeUnlock;//����Ľ���ʱ��
	CString<MaxLockRoomReasonLength> 				strLockRoomReason;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTimeLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTimeUnlock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strLockRoomReason.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTimeLock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTimeUnlock);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strLockRoomReason.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d,nHostID=%d,strHostName=%s,nTimeLock=%lu,nTimeUnlock=%lu ,strLockRoomReason=%s",nRoomID,nHostID,strHostName.GetString(),nTimeLock,nTimeUnlock,strLockRoomReason.GetString());
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSSS_MODIFY_ROOM_CAPACITY_NOTIFY		0x00130717
class CModifyCapacityNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CModifyCapacityNoti()
	{
		nRoomID = enmInvalidRoomID;
		nHostID = enmInvalidRoleID;
		strHostName = "";
		nRoomShowCapacity = 0;
	}
	RoomID 											nRoomID;
	RoleID 											nHostID;
	CString<enmMaxRoleNameLength> 					strHostName; //�������ǳ�
	int32_t  										nRoomShowCapacity;//���޸�Ϊ�����˷�
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomShowCapacity);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nHostID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strHostName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomShowCapacity);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d,nHostID=%d,strHostName=%s,nRoomShowCapacity=%d",nRoomID,nHostID,strHostName.GetString(),nRoomShowCapacity);
		offset = (uint32_t)strlen(buf);
	}
};

//����roomserver����֪ͨ
#define MSGID_RSRD_UPDATEDATA_NOTI		0x00130718
class CUpdateDataNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateDataNoti()
	{
		nType = 0;
		nValue = 0;
		nStartPos = 0;
		nEndPos = 0;
		nDataOffset = 0;
		nDataSize = 0;
		memset(arrData,0,sizeof(arrData));
	}
	UpdateDataType	nType;						//Ҫ���µ��������ͣ�������������ݻ��Ƿ������ݣ�
	int32_t			nValue;						//Ҫ���µ���������ID������Ƿ�������roomid��������������roleid��
	uint32_t		nStartPos;					//���ݵĿ�ʼλ��
	uint32_t		nEndPos;					//���ݵĽ���λ�ã�ͨ���Ϳ�ʼƫ�ƾ���ȷ��һ��������ռ�õ��ڴ��С
	uint32_t		nDataOffset;				//Ҫ���µ�����ƫ��λ��
	int32_t			nDataSize;					//Ҫ���µ����ݴ�С
	uint8_t			arrData[MaxUpdateDataSize];	//Ҫ���µ�����
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nType);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nValue);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nStartPos);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEndPos);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nDataOffset);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nDataSize);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, arrData, nDataSize, sizeof(arrData));
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nType);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nValue);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nStartPos);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEndPos);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nDataOffset);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nDataSize);
		if (0 > nRet) {
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, arrData, nDataSize, sizeof(arrData));
		if (0 > nRet) {
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nType=%d,nValue=%d,nStartPos=%u,nEndPos=%u,nDataOffset=%u,nDataSize=%d}",
				nType, nValue, nStartPos, nEndPos, nDataOffset, nDataSize);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSHS_ONMIC_NOTIFY		0x00130719
class COnMicNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	COnMicNoti()
	{
		nOnMicRoleID = enmInvalidRoleID;
		nMicType = enmMicType_PublicMic;
	}
	RoleID				nOnMicRoleID;
	MicType				nMicType;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nOnMicRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMicType);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nOnMicRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMicType);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nOnMicRoleID=%d,nMicType=%d",nOnMicRoleID,nMicType);
		offset = (uint32_t)strlen(buf);
	}
};
#define MSGID_RSHS_OFFMIC_NOTIFY		0x0013071a
class COffMicNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	COffMicNoti()
	{
		nOffMicRoleID = enmInvalidRoleID;
		nMicType = enmMicType_PublicMic;
	}
	RoleID				nOffMicRoleID;
	MicType				nMicType;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nOffMicRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMicType);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nOffMicRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMicType);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nOffMicRoleID=%d, nMicType=%d}",nOffMicRoleID,nMicType);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSTA_REBULIDSUCCESS_NOTIFY		0x0013071b
class CRebulidSuccessNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRebulidSuccessNoti()
	{
		nRoomID = enmInvalidRoomID;
	}
	RoomID				nRoomID;
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d",nRoomID);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSDB_STA_PLAYER_COUNT_NOTIFY		0x0013071c
class CStaPlayerCount: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID				nRoomID;
	uint32_t			nPlayerCount; //��ʵ��Ҹ���
	uint32_t			nRobotCount;  //�����˸���

	CStaPlayerCount()
	{
		nRoomID = enmInvalidRoomID;
		nPlayerCount = 0;
		nRobotCount = 0;
	}
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRobotCount);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPlayerCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRobotCount);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, nPlayerCount=%d, nRobotCount=%d",nRoomID,nPlayerCount,nRobotCount);
		offset = (uint32_t)strlen(buf);
	}
};


#define MSGID_RSDB_STA_PLAYER_MIC_STATUS		0x0013071d
class CStaPlayerMicStatus: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID								nRoomID;
	RoleID								nRoleID;
	CString<MaxRoleNameLength> 			strRoleName; //����ǳ�
	IdentityType                        nIdentityType;//���
	int32_t 							nMicResult;
	MicOperateType						nMicOperateType;
	int32_t 							nMsgID;   //���Ӱ���MSGID
	int32_t							nTime;

	CStaPlayerMicStatus()
	{
		nRoomID = enmInvalidRoomID;
		nRoleID = enmInvalidRoleID;
		strRoleName = "";
		nIdentityType = enmIdentityType_None;
		nMicResult = 0;
		nMicOperateType = 0;
		nMsgID = 0;
		nTime = 0;
	}
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMicResult);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMicOperateType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMsgID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMicResult);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMicOperateType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMsgID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nRoleID=%d, strRoleName=%s, nIdentityType=%d, nMicResult=%d, nMicOperateType=%d, nMsgID=0x%08x,nTime=%d}",nRoomID,nRoleID,strRoleName.GetString(),nIdentityType,nMicResult,nMicOperateType,nMsgID,nTime);
		offset = (uint32_t)strlen(buf);
	}
};


#define MSGID_RSDB_UPDATESONGLIST_NOTI		0x0011071e
class CUpdateSongListNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID								nRoomID;
	RoleID								nSongerRoleID;
	uint16_t							nSongCount;
	uint16_t							arrSongIndex[MaxSongCountPerPlayer];
	CString<MaxSongNameLength>			arrSongName[MaxSongCountPerPlayer];
	uint32_t							arrSongAttr[MaxSongCountPerPlayer];

	CUpdateSongListNoti()
	{
		nRoomID = enmInvalidRoomID;
		nSongerRoleID = enmInvalidRoleID;
		nSongCount = 0;
	}
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nSongCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrSongIndex[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSongName[i].MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrSongAttr[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nSongCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrSongIndex[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSongName[i].MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrSongAttr[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nRoleID=%d, nSongCount=%d, arrSongInfo={",
				nRoomID,nSongerRoleID,nSongCount);
		offset = (uint32_t)strlen(buf);
//		for(int32_t i = 0; i < nSongCount - 1; ++i)
//		{
//			sprintf(buf + offset, "{SongIndex=%d, SongName=%s, SongAttr=%d}, ",arrSongIndex[i], arrSongName[i].GetString(), arrSongAttr[i]);
//			offset = (uint32_t)strlen(buf);
//		}
//		if(nSongCount > 0)
//		{
//			sprintf(buf + offset, "{SongIndex=%d, SongName=%s, SongAttr=%d}", arrSongIndex[nSongCount - 1],
//					arrSongName[nSongCount - 1].GetString(), arrSongAttr[nSongCount - 1]);
//			offset = (uint32_t)strlen(buf);
//		}
		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_RSDB_GETSONGLISTFROMDB_REQ		0x00110720
class CGetSongListFromDBReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID								nRoomID;
	RoleID								nSongerRoleID;

	CGetSongListFromDBReq()
	{
		nRoomID = enmInvalidRoomID;
		nSongerRoleID = enmInvalidRoleID;
	}
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nRoleID=%d}",nRoomID,nSongerRoleID);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_DBRS_GETSONGLISTFROMDB_RESP		0x00120720
class CGetSongListFromDBResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t								nResult;
	RoomID								nRoomID;
	RoleID								nSongerRoleID;
	uint16_t							nSongCount;
	uint16_t							arrSongIndex[MaxSongCountPerPlayer];
	CString<MaxSongNameLength>			arrSongName[MaxSongCountPerPlayer];
	uint32_t							arrSongAttr[MaxSongCountPerPlayer];

	CGetSongListFromDBResp()
	{
		nResult = 0;
		nRoomID = enmInvalidRoomID;
		nSongerRoleID = enmInvalidRoleID;
		nSongCount = 0;
	}
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nSongCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrSongIndex[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSongName[i].MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrSongAttr[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nResult < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nSongCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrSongIndex[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSongName[i].MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrSongAttr[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d", nResult);
		offset = (uint32_t)strlen(buf);
		if(nResult < 0)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, ", nRoomID=%d, nRoleID=%d, nSongCount=%d, arrSongInfo={",nRoomID,nSongerRoleID,nSongCount);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nSongCount - 1; ++i)
			{
				sprintf(buf + offset, "{SongIndex=%d, SongName=%s, SongAttr=%d}, ",arrSongIndex[i], arrSongName[i].GetString(), arrSongAttr[i]);
				offset = (uint32_t)strlen(buf);
			}
			if(nSongCount > 0)
			{
				sprintf(buf + offset, "{SongIndex=%d, SongName=%s, SongAttr=%d}", arrSongIndex[nSongCount - 1],
						arrSongName[nSongCount - 1].GetString(), arrSongAttr[nSongCount - 1]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
		}
	}
};

#define MSGID_RSDB_UPDATESONGORDERINFO_NOTI		0x00130721
class CUpdateSongOrderInfoNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	RoomID								nRoomID;			//�����
	int64_t								nOrderStartTime;	//��������ʱ��
	int64_t								nOrderEndTime;		//��������ʱ��
	OrderStatus							nOrderStatus;		//����״̬
	CString<MaxSongNameLength>			strSongName;		//��ĸ�����
	RoleID								nSongerRoleID;		//����roleid
	CString<MaxRoleNameLength>			strSongerName;		//�����ǳ�
	RoleID								nRequestRoleID;		//�����roleid
	CString<MaxRoleNameLength>			strRequestName;		//�������ǳ�
	CString<MaxWishWordsLength>			strWishWords;		//ף����
	uint32_t							nOrderCost;			//������
	uint16_t							nSongCount;
	uint16_t							nTotalTicketCount;			//�����ܹ���ЧƱ��
	uint16_t							nGerneralGiveupCount;		//����������Ȩ��
	uint16_t							nGerneralGoodCount;			//���������Ʊ��
	uint16_t							nGerneralBadCount;			//���������Ʊ��
	uint16_t							nRequesterGiveupCount;		//�������Ȩ��
	uint16_t							nRequesterGoodCount;		//����ߺ�Ʊ��
	uint16_t							nRequesterBadCount;			//����߲�Ʊ��
	uint16_t							nMarkResult;

	CUpdateSongOrderInfoNoti()
	{
		strTransID.Initialize();
		nRoomID = enmInvalidRoomID;
		nOrderStartTime = 0;
		nOrderEndTime = 0;
		nOrderStatus = 0;
		strSongName.Initialize();
		nSongerRoleID = enmInvalidRoleID;
		strSongerName.Initialize();
		nRequestRoleID = enmInvalidRoleID;
		strRequestName.Initialize();
		strWishWords.Initialize();
		nOrderCost = 0;
		nTotalTicketCount = 0;
		nGerneralGiveupCount = 0;
		nGerneralGoodCount = 0;
		nGerneralBadCount = 0;
		nRequesterGiveupCount = 0;
		nRequesterGoodCount = 0;
		nRequesterBadCount = 0;
		nMarkResult = 0;
	}
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = strTransID.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nOrderStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nOrderEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nOrderStatus);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strSongName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strSongerName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRequestRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRequestName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strWishWords.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nOrderCost);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTotalTicketCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nGerneralGiveupCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nGerneralGoodCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nGerneralBadCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRequesterGiveupCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRequesterGoodCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRequesterBadCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMarkResult);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = strTransID.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nOrderStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nOrderEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nOrderStatus);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strSongName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongerRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strSongerName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRequestRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRequestName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strWishWords.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nOrderCost);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSongCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTotalTicketCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGerneralGiveupCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGerneralGoodCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGerneralBadCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRequesterGiveupCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRequesterGoodCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRequesterBadCount);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMarkResult);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;

	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strTransID=%s, nRoomID=%d, nOrderStartTime=%ld, nOrderEndTime=%ld, "
				"nOrderStatus=%d, nSongerRoleID=%d, strSongName=%s, nRequestRoleID=%d, strRequestName=%s, "
				"strWishWords=%s, nOrderCost=%u, nSongCount=%d, nTotalTicketCount=%d, "
				"nGerneralGiveupCount=%d, nGerneralGoodCount=%d, nGerneralBadCount=%d, nRequesterGiveupCount=%d, "
				"nRequesterGoodCount=%d, nRequesterBadCount=%d, nMarkResult=%d}",strTransID.GetString(), nRoomID, nOrderStartTime,
				nOrderEndTime, nOrderStatus, nSongerRoleID, strSongName.GetString(), nRequestRoleID,
				strRequestName.GetString(), strWishWords.GetString(), nOrderCost, nSongCount, nTotalTicketCount,
				nGerneralGiveupCount, nGerneralGoodCount, nGerneralBadCount,
				nRequesterGiveupCount, nRequesterGoodCount, nRequesterBadCount, nMarkResult);
		offset = (uint32_t)strlen(buf);
	}
};


//��ȡ��������Ϣ
#define MSGID_RSDB_GETROLEIDENTITY_REQ         0x00110722
class CGetOfflineArtistInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID      nRoleID;
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d}",nRoleID);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_DBRS_GETROLEIDENTITY_RESP      	0x120722
class CGetOfflineArtistInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t    nResult;
	RoleID      	 				nRoleID ;
	VipLevel	 					nGender ;
	uint32_t	 					n179ID ;
	CString<MaxRoleNameLength>		strRoleName ;
	VipLevel						nVipLevel ;
	RoleRank						nRoleRank ;
	IdentityType                    nIdentityType ;
	uint16_t						nClientInfo ;
	MagnateLevel 					nMagnateLevel ;
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
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
		nRet = CCodeEngine::Decode(buf, size, offset, nGender);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, n179ID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageDecode(buf, size, offset);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nClientInfo);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMagnateLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
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
		nRet = CCodeEngine::Encode(buf, size, offset, nGender);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, n179ID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strRoleName.MessageEncode(buf, size, offset);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nIdentityType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nClientInfo);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nIdentity=%d, nVipLevel=%d, n179ID=%d, nMagnateLevel=%d,"
				" nClientInfo=%d, nRoleRank=%d}",
				nResult, nIdentityType, nVipLevel, n179ID, nMagnateLevel,nClientInfo, nRoleRank);
		offset = (uint32_t)strlen(buf);
	}
};


//��ȡ����������Ϣ
#define  MSGID_RSDB_GETROOMARTIST_REQ        0x00110723
class CGetRoomArtistReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID      nRoomID;
public:
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d}",nRoomID);
		offset = (uint32_t)strlen(buf);
	}
};

#define  MSGID_RSDB_GETROOMARTIST_RESP        0x00120723
class CGetRoomArtistResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t      					nResult;
	int32_t      					nCount;              //�����б�����
	RoleID      	 				arrRoleID[MAX_ARTIST_NUM];
	VipLevel	 					arrGender[MAX_ARTIST_NUM];
	uint32_t	 					arr179ID[MAX_ARTIST_NUM];
	CString<MaxRoleNameLength>		strRoleName[MAX_ARTIST_NUM];
	VipLevel						arrVipLevel[MAX_ARTIST_NUM];
	UserLevel						arrUserLevel[MAX_ARTIST_NUM];
	RoleRank						arrRoleRank[MAX_ARTIST_NUM];
	IdentityType                    arrIdentityType[MAX_ARTIST_NUM];
	uint16_t						arrClientInfo[MAX_ARTIST_NUM];
	MagnateLevel 					arrMagnateLevel[MAX_ARTIST_NUM];
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0 ; i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrGender[i]);
			if(0 > nRet)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(buf, size, offset, arr179ID[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = strRoleName[i].MessageEncode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrVipLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrUserLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleRank[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrIdentityType[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrClientInfo[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrMagnateLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0 ; i < nCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrGender[i]);
			if(0 > nRet)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(buf, size, offset, arr179ID[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = strRoleName[i].MessageDecode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrVipLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrUserLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleRank[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrIdentityType[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrClientInfo[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrMagnateLevel[i]);
			if(0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nCount=%d, ", nResult, nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "{RoleID=%d, nGender=%d, 179ID=%d, RoleName=%s, VipLevel=%d,"
					"UserLevel=%d, RoleRank=%d, IdentityType=%d, ClientInfo=%d, MagnateLevel=%d},",
					arrRoleID[i], arrGender[i],  arr179ID[i],  strRoleName[i].GetString(),
					arrVipLevel[i], arrUserLevel[i], arrRoleRank[i], arrIdentityType[i],
					arrClientInfo[i], arrMagnateLevel[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}
};

//add your message to map
MESSAGEMAP_DECL_BEGIN(roomserver)
MESSAGEMAP_DECL_MSG(MSGID_RSMS_ENTER_ROOM_NOTICE, (new CEnterRoomNotice_Public()))
MESSAGEMAP_DECL_MSG(MSGID_RSMS_EXIT_ROOM_NOTICE, (new CExitRoomNotice_Public()))
MESSAGEMAP_DECL_MSG(MSGID_RSMS_CREATE_ROOM_NOTICE, (new CCreateRoomNotice_Public()))
MESSAGEMAP_DECL_MSG(MSGID_RSMS_DESTORY_ROOM_NOTICE, (new CDestoryRoomNotice_Public()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_SET_ROOM_REQ, (new CSetRoomAttrReq()))
MESSAGEMAP_DECL_MSG(MSGID_RSHS_GET_ROLE_GLOBALINFO_REQ, (new CGetRoleGlobalInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_ADD_ONLINE_TIME_INROOM_NOTICE, (new CAddAdmInRoomOnLineTimeNotice()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_ADD_ONMIC_TIME_INROOM_NOTICE, (new CAddOnMicTimeNotice()))
MESSAGEMAP_DECL_MSG(MSGID_RSIS_GET_ITEMINFO_REQ, (new CGetItemInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_ADD_BLACK_REQ, (new CAddPlayerToBlackReq()))
MESSAGEMAP_DECL_MSG(MSGID_RSSS_LOCK_ROOM_NOTIFY, (new CLockRoomToSysNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSSS_MODIFY_ROOM_CAPACITY_NOTIFY, (new CModifyCapacityNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSRD_UPDATEDATA_NOTI, (new CUpdateDataNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSHS_ONMIC_NOTIFY, (new COnMicNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSHS_OFFMIC_NOTIFY, (new COffMicNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSTA_REBULIDSUCCESS_NOTIFY, (new CRebulidSuccessNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_STA_PLAYER_COUNT_NOTIFY, (new CStaPlayerCount()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_STA_PLAYER_MIC_STATUS, (new CStaPlayerMicStatus()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_UPDATESONGLIST_NOTI, (new CUpdateSongListNoti()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_GETSONGLISTFROMDB_REQ, (new CGetSongListFromDBReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBRS_GETSONGLISTFROMDB_RESP, (new CGetSongListFromDBResp()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_UPDATESONGORDERINFO_NOTI, (new CUpdateSongOrderInfoNoti()))
//MSGID_RSDB_SET_TITLE_REQ
MESSAGEMAP_DECL_MSG(MSGID_RSDB_GETROLEIDENTITY_REQ, (new CGetOfflineArtistInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBRS_GETROLEIDENTITY_RESP, (new CGetOfflineArtistInfoResp()))

MESSAGEMAP_DECL_MSG(MSGID_RSDB_GETROOMARTIST_REQ, (new CGetRoomArtistReq()))
MESSAGEMAP_DECL_MSG(MSGID_RSDB_GETROOMARTIST_RESP, (new CGetRoomArtistResp()))

MESSAGEMAP_DECL_END()



FRAME_NAMESPACE_END

#endif /* ROOMSERVER_MESSAGE_DEFINE_H_ */
