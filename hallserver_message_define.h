/*
 * hallserver_message_define.h
 *
 *  Created on: 2011-12-4
 *      Author: jimm
 */

#ifndef HALLSERVER_MESSAGE_DEFINE_H_
#define HALLSERVER_MESSAGE_DEFINE_H_

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
//#include "frame/impl/frame_protocol_impl.h"
#include "frame_protocolhead.h"
#include "public_typedef.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include "common/common_codeengine.h"
#include "roomserver_message_define.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

//�û���½��Ϣ����
#define MSGID_HSDB_GETROLELOGININFO_REQ			0x00110401
class CHallGetRoleLoginInfoReq_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CHallGetRoleLoginInfoReq_Public()
	{
		nRoleID = enmInvalidRoleID;
		nIpAddr = 0;
		strMacAddr.Initialize();
		nChannelID = enmInvalidChannelID;
		nOSVersion = 0;
		strAccountName.Initialize();
	}
	virtual ~CHallGetRoleLoginInfoReq_Public()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nIpAddr);
		if (0 > ret)
		{
			return ret;
		}

		ret = strMacAddr.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nOSVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = strAccountName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nIpAddr);
		if (0 > ret)
		{
			return ret;
		}

		ret = strMacAddr.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nOSVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = strAccountName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nRoleID=%d, nIpAddr=%s, nMacAddr=%s, nChannelID=%d, nOSVersion=%d, strAccountName=%s}\n",
				nRoleID, inet_ntoa_f(nIpAddr), strMacAddr.GetString(), nChannelID, nOSVersion, strAccountName.GetString());
	    offset = (uint32_t)strlen(buf);
	}
public:
	RoleID			nRoleID;
	uint32_t		nIpAddr;
	CString<MaxMacAddrStringLength> strMacAddr;
	ChannelID       nChannelID;      //��½������
	int32_t			nOSVersion;
	CString<MaxAccountName> strAccountName;
};

//�û���½��Ϣ��Ӧ
#define MSGID_DBHS_GETROLELOGININFO_RESP		0x00120401
class CHallGetRoleInfoResp_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Encode(buf, size, offset, nTimelock);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}
		ret = strAccountLockReason.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}

		ret = strAccountName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLastVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLastLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nSystemTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGender);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUserLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nOnlineTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLeftTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLeftMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLastLogoutTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nExperience);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAdminCount);
		if (0 > ret)
		{
			return ret;
		}
		for (int32_t i = 0; i < nAdminCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoomIDS[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		for (int32_t i = 0; i < nAdminCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoleRank[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		ret = CCodeEngine::Encode(buf, size, offset, uRoleIdentity);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nBecomeVipTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUserInfoSelfSet);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRmbUserType);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAccountSafeType);
		if(0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Encode(buf, size, offset, nIpAddr);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLockIPEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = strMacAddr.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLockMacEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLockIPStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLockMacStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLockIpReason.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = strLockMacReason.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMagnatelevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nConsume);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nNextlevelMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nTimelock);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}
		ret = strAccountLockReason.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strAccountName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLastVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLastLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nSystemTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGender);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUserLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nOnlineTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLeftTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLeftMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLastLogoutTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nExperience);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAdminCount);
		if (0 > ret)
		{
			return ret;
		}
		for (int32_t i = 0; i < nAdminCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoomIDS[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		for (int32_t i = 0; i < nAdminCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoleRank[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		ret = CCodeEngine::Decode(buf, size, offset, uRoleIdentity);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nBecomeVipTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUserInfoSelfSet);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRmbUserType);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAccountSafeType);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nIpAddr);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLockIPEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = strMacAddr.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLockMacEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLockIPStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLockMacStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLockIpReason.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = strLockMacReason.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMagnatelevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nConsume);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nNextlevelMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (0 > nResult)
		{
			sprintf(buf + offset, "}");
			offset = strlen(buf);
			return;
		}
		sprintf(buf + offset,"Timelock=%lu, nTimeUnlock=%lu, strAccountLockReason=%s, "
			"nRoleID=%d, strAccountName=%s, nAccountID=%d nLastVersion=%d, nLastLoginTime=%lu, nSystemTime=%lu, "
			"Gender=%d, strRoleName=%s, nVipLevel=%d, nUserLevel=%d, nOnlineTime=%lu, "
			"nLeftTime=%lu, nLeftMoney=%u, nLastLogoutTime=%lu, nExperience=%d, nUserInfoSelfSet=%d, ",
			nTimelock, nTimeUnlock, strAccountLockReason.GetString(),nRoleID, strAccountName.GetString(), nAccountID, nLastVersion,
			nLastLoginTime, nSystemTime,nGender, strRoleName.GetString(),
			nVipLevel,nUserLevel, nOnlineTime, nLeftTime, nLeftMoney,
			nLastLogoutTime, nExperience, nUserInfoSelfSet);
		offset = (uint32_t) strlen(buf);

		sprintf(buf + offset, "nAdminCount=%d, ", nAdminCount);
		offset = (uint32_t) strlen(buf);

		for (int32_t i = 0; i < nAdminCount; ++i)
		{
			sprintf(buf + offset, "{roomid[%d]=%d, rolerand[%d]=%d}, ", 
				i, arrRoomIDS[i], i, arrRoleRank[i]);
			offset = (uint32_t) strlen(buf);
		}
		offset = (uint32_t) strlen(buf);

		sprintf(buf + offset, "roleidentity=%d, nBecomeVipTime=%d, ", uRoleIdentity, (int32_t)nBecomeVipTime);
		offset = (uint32_t)strlen(buf);
		sprintf(buf + offset, "nRmbUserType=%d, nAccountSafeType=%d, ", nRmbUserType, nAccountSafeType);
		offset = (uint32_t)strlen(buf);

		sprintf(buf + offset, "ip=%s,lockipstarttime=%ld,lockipendtime=%ld,lockipreason=%s,",
			inet_ntoa_f(nIpAddr),nLockIPStartTime, nLockIPEndTime, strLockIpReason.GetString());
		offset = (uint32_t)strlen(buf);

		sprintf(buf + offset, "mac=%s,lockmacstarttime=%ld,lockmacendtime=%ld,lockmacreason=%s,",
			strMacAddr.GetString(),nLockMacStartTime, nLockMacEndTime, strLockMacReason.GetString());
		offset = (uint32_t)strlen(buf);

		sprintf(buf + offset,"nMagnatelevel=%d,nConsume=%ld,nNextlevelMoney=%ld, nChannelID=%d}\n",
			nMagnatelevel,nConsume,nNextlevelMoney, nChannelID);
		offset = (uint32_t)strlen(buf);

	}
public:
	CHallGetRoleInfoResp_Public()
	{
		nResult = enmDefault_ErrorCode;
		nTimelock = 0;
		nTimeUnlock = 0;
		strAccountLockReason.Initialize();
		nRoleID = enmInvalidRoleID;
		strAccountName.Initialize();
		nAccountID = enmInvalidAccountID;
		nLastVersion = enmInvalidVersion;
		nLastLoginTime = enmInvalidTimeVal;
		nSystemTime = enmInvalidTimeVal;
		nGender = enmGender_Male;
		strRoleName.Initialize();
		nVipLevel = enmInvalidVipLevel;
		nUserLevel = enmInvalidLevel;
		nOnlineTime = enmInvalidOnlineTime;
		nLeftTime = enmInvalidLeftTime;
		nLeftMoney = enmInvalidLeftMoney;
		nLastLogoutTime = enmInvalidTimeVal;
		nExperience = enmInvalidExpVal;
		nAdminCount = 0;
		memset(arrRoomIDS, 0, sizeof(arrRoomIDS));
		memset(arrRoleRank, 0, sizeof(arrRoleRank));
		uRoleIdentity = 0;
		nBecomeVipTime = 0;
		nUserInfoSelfSet = 0;
		nRmbUserType = 0;
		nAccountSafeType = 0;
		nIpAddr = 0;
		nLockIPEndTime = 0;
		strMacAddr.Initialize();
		nLockMacEndTime = 0;
		nLockIPStartTime = 0;
		nLockMacStartTime = 0;
		strLockIpReason.Initialize();
		strLockMacReason.Initialize();

		nMagnatelevel = enmMagnateLevel_0;
		nConsume = 0;
		nNextlevelMoney = 0;
		nChannelID = enmInvalidChannelID;
	}
	virtual ~CHallGetRoleInfoResp_Public()
	{

	}
public:
	int32_t nResult;
	uint64_t nTimelock;//������0
	uint64_t nTimeUnlock;//������0
	CString<MaxLockPlayerReasonLength> strAccountLockReason;//����ԭ���128�ֽ�
	RoleID nRoleID;
	CString<MaxAccountName> strAccountName;
	AccountID nAccountID;
	uint32_t nLastVersion;
	uint64_t nLastLoginTime;
	uint64_t nSystemTime;
	Gender nGender;
	CString<MaxRoleNameLength> strRoleName;
	VipLevel nVipLevel;
	UserLevel nUserLevel;
	uint64_t nOnlineTime;
	uint64_t nLeftTime;
	uint32_t nLeftMoney;
	uint64_t nLastLogoutTime;
	int32_t nExperience;
	int32_t nAdminCount;
	RoomID arrRoomIDS[MaxBeAdminPerPlayer];
	RoleRank arrRoleRank[MaxBeAdminPerPlayer];
	IdentityType uRoleIdentity;
	uint64_t nBecomeVipTime; //�û���Ϊvip��ʱ��
	uint32_t nUserInfoSelfSet;
	int32_t  nRmbUserType;       //�Ƿ�Ϊ������ң��Ǹ������Ϊ0�� �������Ϊ1
	int32_t  nAccountSafeType;   //�Ƿ������ܱ���û������Ϊ0�� �Ѿ�����Ϊ1
	uint32_t nIpAddr;			//ip
	uint64_t nLockIPEndTime;		//��ip����ʱ��
	CString<MaxMacAddrStringLength> strMacAddr; //mac
	uint64_t nLockMacEndTime;		//��Mac����ʱ��
	uint64_t nLockIPStartTime;
	uint64_t nLockMacStartTime;
	CString<MaxLockIPReasonLength> strLockIpReason;//lock ip reason
	CString<MaxLockIPReasonLength> strLockMacReason;//lock mac reason

	MagnateLevel    nMagnatelevel;               //�����ȼ�
	uint64_t        nConsume;                    //������Ѷ�
	uint64_t        nNextlevelMoney;             //��һ���ȼ���Ҫ�����Ѷ�

	ChannelID       nChannelID;                  //��½������
};

//��ȡ������Ϣ
#define MSGID_HSDB_GETROOMINFO_REQ				0x00110402
class CHallGetRoomInfoReq_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nRoomID=%d\n}\n", nRoomID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	CHallGetRoomInfoReq_Public()
	{
		nRoomID = enmInvalidRoomID;
	}
	virtual ~CHallGetRoomInfoReq_Public()
	{

	}
public:
	RoomID nRoomID;
};

#define MSGID_DBHS_GETROOMINFO_RESP				0x00120402
class CHallGetRoomInfoResp_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Encode(buf, size, offset, nRegionType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRegionID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRegionName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strChannelName.MessageEncode(buf, size, offset);
		if(0>ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoomName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nRegionType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRegionID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRegionName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nChannelID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strChannelName.MessageDecode(buf, size, offset);
		if(0>ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoomName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "MsgBody={nResult=%d, ", nResult);
	    offset = (uint32_t)strlen(buf);
	    if(nResult < 0)
	    {
	    	sprintf(buf + offset, "}");
	    }
	    else
	    {
			sprintf(buf + offset, "nRegionType=%d, nRegionID=%d, strRegionName=%s, nChannelType=%d,"
			"nChannelID=%d, strChannelName=%s, nRoomType=%d, nRoomID=%d, strRoomName=%s}\n",
			nRegionType, nRegionID, strRegionName.GetString(), nChannelType, nChannelID,
			strChannelName.GetString(), nRoomType, nRoomID, strRoomName.GetString());
	    }
	    offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nResult;
	RegionType nRegionType;
	RegionID nRegionID;
	CString<MaxRegionNameLength> strRegionName;
	ChannelType nChannelType;
	ChannelID nChannelID;
	CString<MaxChannelNameLength> strChannelName;
	RoomType nRoomType;
	RoomID nRoomID;
	CString<MaxRoomNameLength> strRoomName;
};

#define MSGID_HSTA_ONLINE_NOTI					0x00130403
class COnlineNoti: public IMsgBody
{
	SIZE_INTERFACE();
public: COnlineNoti()
		{
			nRoleID = 0;
			strRoleName.Initialize();
			nAccountID = enmInvalidAccountID;
			nVipLevel = enmVipLevel_NONE;
			nLeftMoney = 0;
			nLoginTime = 0;
			nMagnatelevel = 0;
			nConsume = 0;
			nNextlevelMoney = 0;
			nGender = enmGender_Unknown;
		}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLeftMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = nConnUin.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMagnatelevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nConsume);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nNextlevelMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGender);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLeftMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = nConnUin.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMagnatelevel);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nConsume);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nNextlevelMoney);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGender);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "MsgBody={nRoleID=%d, nLoginTime=%ld, strRoleName=%s, nAccountID=%d, "
	    		"nVipLevel=%d, nLeftMoney=%d, nConnUin={nVersion=%d, nServerID=%d, nTunnelIndex=%d, nRoleID=%d,"
	    		"nCreateTime=%d, nIsn=%d, nAddress=%s, nPort=%d, nNetType=%d, nAccountType=%d}, "
				"nMagnatelevel=%d,nConsume=%ld,nNextlevelMoney=%ld,Gender=%u}\n",
	    		nRoleID, nLoginTime, strRoleName.GetString(), nAccountID, nVipLevel, nLeftMoney,
	    		nConnUin.nVersion, nConnUin.nServerID, nConnUin.nTunnelIndex, nConnUin.nRoleID,
	    		nConnUin.nCreateTime, nConnUin.nIsn, inet_ntoa_f(nConnUin.nAddress), nConnUin.nPort,
	    		nConnUin.nNetType, nConnUin.nAccountType, nMagnatelevel, nConsume, nNextlevelMoney,nGender);
	    offset = (uint32_t)strlen(buf);
	}

public:
	RoleID nRoleID;
	CString<MaxRoleNameLength> strRoleName;
	AccountID nAccountID;
	VipLevel nVipLevel;
	uint32_t nLeftMoney;
	int64_t nLoginTime;
	ConnUin nConnUin;
	MagnateLevel    nMagnatelevel;               //�����ȼ�
	uint64_t        nConsume;                    //������Ѷ�
	uint64_t        nNextlevelMoney;             //��һ���ȼ���Ҫ�����Ѷ�
	Gender		    nGender;
};

#define MSGID_HSTA_OFFLINE_NOTI					0x00130404
class COfflineNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLogoutTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = nConnUin.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLogoutReason);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLogoutTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = nConnUin.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLogoutReason);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoleID=%d, nLogoutTime=%ld, nConnUin={nVersion=%d, nServerID=%d, nTunnelIndex=%d, nRoleID=%d, "
	    		"nCreateTime=%d, nIsn=%d, nAddress=%s, nPort=%d, nNetType=%d}, nLogoutReason=%d}",
	    		nRoleID, nLogoutTime, nConnUin.nVersion, nConnUin.nServerID, nConnUin.nTunnelIndex, nConnUin.nRoleID,
	    		nConnUin.nCreateTime, nConnUin.nIsn, inet_ntoa_f(nConnUin.nAddress), nConnUin.nPort, nConnUin.nNetType,
	    		nLogoutReason);
	    offset = (uint32_t)strlen(buf);
	}

public:
	RoleID nRoleID;
	int64_t nLogoutTime;
	ConnUin nConnUin;
	LogoutReason nLogoutReason;
};

/*
 * Э�鹦�ܣ���ѯĳ�������ĳһ����Ա�ȼ��Ĺ���Ա�ĸ���
 */
#define MSGID_HSDB_GETROOM_ADMIN_COUNT_REQ    0x00110405
class CHallGetRoomAdminCountReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID uRoomID; /*����ID*/
	RoleRank usRoleRank; /*Ҫ��ѯ��Ȩ��*/
public:
	CHallGetRoomAdminCountReq()
	{
		uRoomID = enmInvalidRoomID;
		usRoleRank = enmRoleRank_None;
	}
	virtual ~CHallGetRoomAdminCountReq()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, uRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, usRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, uRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, usRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={roomid=%d, rolerank=%d}", uRoomID, usRoleRank);
		offset = (uint32_t) strlen(buf);
	}
};

#define MSGID_DBHS_GETROOM_ADMIN_COUNT_RESP    0x00120405
class CHallGetRoomAdminCountResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult; /*����ֵ*/
	RoomID uRoomID; /*����ID*/
	RoleRank usRoleRank; /*����ԱȨ�ޣ����������������ٹܵȵ�*/
	int32_t nRoomShowCapacity; /*�������ʾ����*/
	//RoomType  ucRoomType;          /*��������*/
	int32_t nAdminCount; /*����Ա�ĸ���*/
public:
	CHallGetRoomAdminCountResp()
	{
		nResult = 0;
		uRoomID = enmInvalidRoomID;
		usRoleRank = enmRoleRank_None;
		nRoomShowCapacity = 0;
		//ucRoomType = enmInvalidRoomType;
		nAdminCount = 0;
	}
	virtual ~CHallGetRoomAdminCountResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (nResult < 0)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, uRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, usRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomShowCapacity);
		if (0 > ret)
		{
			return ret;
		}
		//ret = CCodeEngine::Encode(buf, size, offset, ucRoomType);
		//if(0 > ret)
		//{
		//	return ret;
		//}
		ret = CCodeEngine::Encode(buf, size, offset, nAdminCount);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		if (nResult < 0)
		{
			return S_OK;
		}
		ret = CCodeEngine::Decode(buf, size, offset, uRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, usRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomShowCapacity);
		if (0 > ret)
		{
			return ret;
		}
		//ret = CCodeEngine::Decode(buf, size, offset, ucRoomType);
		//if(0 > ret)
		//{
		//	return ret;
		//}
		ret = CCodeEngine::Decode(buf, size, offset, nAdminCount);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={result=%d, roomid=%d, rolerank=%d, roomRealCapacity=%d, admincount=%d}\n",
			nResult,
			uRoomID,
			usRoleRank,
			nRoomShowCapacity,
			nAdminCount);
		offset = (uint32_t)strlen(buf);
	}
};
#define MSGID_HSDB_SET_TITLE_REQ    0x00110406
class CHallSetTitleReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nDestRoleID;
	RoomID nRoomID;
	RoleRank nRoleRank;
	RoleID nSrcRoleID;
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nSrcRoleID);
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nDestRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nSrcRoleID);
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nDestRoleID=%d, nRoomID=%d, nRoleRank=%d,nSrcRoleID=%d}\n", nDestRoleID,
				nRoomID,nRoleRank,nSrcRoleID);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_DBHS_SET_TITLE_RESP    0x00120406
class CHallSetTitleResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult; //����S_OKΪ�ɹ���С��0Ϊʧ��
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}", nResult);
		offset = (uint32_t) strlen(buf);
	}
};
//�޸�Ȩ��֪ͨ
#define MSGID_HSTA_MODIFY_TITLE_NOTIFY			0x00130407
class CModifyTitleNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoleRank);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleRank);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nRoleID=%d, nRoomID=%d, nRoleRank=%d}",
	    		nRoleID,nRoomID,nRoleRank);
	    offset = (uint32_t)strlen(buf);
	}

public:
	RoleID nRoleID;//��������
	RoomID nRoomID;//���ڵķ���
	RoleRank nRoleRank;//��Ϊɾ������Ȩ������enmRoleRank_None
};

//���͸�DB�޸�user_base_config�������
#define MSGID_HSDB_SETSELFINFO_REQ		0x00110407
class CHallSetSelfInfoReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;
	uint8_t nSetInfoCount;
	UserInfoType nUserInfoType;
	uint32_t nUserInfoSelfSet;

public:
	CHallSetSelfInfoReq()
	{
		nRoleID = enmInvalidRoleID;
		nSetInfoCount = 0;
		nUserInfoType = enmUserInfoType_Invalid;
		nUserInfoSelfSet = 0;
	}
	virtual ~CHallSetSelfInfoReq()
	{
	}

public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nSetInfoCount);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUserInfoType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUserInfoSelfSet);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size,
			uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nSetInfoCount);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUserInfoType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUserInfoSelfSet);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(
				buf + offset,
				"MsgBody={nRoleID=%d, nSetInfoCount=%d, nUserInfoType=0x%02X, nUserInfoSelfSet=%d}\n",
				nRoleID, (uint32_t) nSetInfoCount, nUserInfoType,
				nUserInfoSelfSet);
		offset = (uint32_t) strlen(buf);
	}
};

//�޸�������Ϣ����Ӧ
#define MSGID_DBHS_SETSELFINFO_RESP 	0x00120407
class CDBSetSelfSelfInfoResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	uint32_t nResult;//С��0Ϊʧ��,S_OKΪ�ɹ�
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size,
			uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nResult=%d}\n", nResult);
		offset = (uint32_t) strlen(buf);
	}
};

#define MSGID_HSRS_SETSELFSETTING_NOTI    0x00130408
class CHallSetSelfSettingNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;
	PlayerSelfSetting nPlayerSelfSetting;
public:
	CHallSetSelfSettingNoti()
	{
		nRoleID = 0;
		nPlayerSelfSetting = 0;
	}
	virtual ~CHallSetSelfSettingNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPlayerSelfSetting);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPlayerSelfSetting);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d, nPlayerSelfSetting=%d\n",
				nRoleID,
				nPlayerSelfSetting);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_HSRS_UPDATEGLOBALSTATE_NOTI    0x00130409
class CHallUpdateGlobalStateNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;
	PlayerState nPlayerState;
public:
	CHallUpdateGlobalStateNoti()
	{
		nRoleID = 0;
		nPlayerState = 0;
	}
	virtual ~CHallUpdateGlobalStateNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPlayerState);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPlayerState);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nPlayerState=%d\n}",
				nRoleID,
				nPlayerState);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_HSDB_SETLOGININFO_NOTI		0x0013040a
class CSetLoginInfoNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetLoginInfoNoti()
	{
		nRoleID = enmInvalidRoleID;
		nLoginTime = 0;
		nIPAddr = 0;
		nOSVersion = 0;
		strMacAddr.Initialize();
		nChannel = 0;
	}

	virtual ~CSetLoginInfoNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nIPAddr);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nOSVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = strMacAddr.MessageEncode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nChannel);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLoginTime);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nIPAddr);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nOSVersion);
		if (0 > ret)
		{
			return ret;
		}
		ret = strMacAddr.MessageDecode(buf, size, offset);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nChannel);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nRoleID=%d, nLoginTime=%ld, nIPAddr=%s, nOSVersion=%u, strMacAddr=%s, nChannel=%u}\n",
				nRoleID, nLoginTime, inet_ntoa_f(nIPAddr), nOSVersion, strMacAddr.GetString(), nChannel);
		offset = (uint32_t) strlen(buf);
	}

public:
	RoleID		nRoleID;
	int64_t		nLoginTime;
	uint32_t	nIPAddr;
	uint32_t	nOSVersion;
	CString<MaxMacAddrStringLength> strMacAddr;
	uint32_t nChannel;
};

#define MSGID_HSDB_SETLOGOUTINFO_NOTI		0x0013040b
class CSetLogoutInfoNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetLogoutInfoNoti()
	{
		nRoleID = enmInvalidRoleID;
		nLogoutTime = 0;
	}

	virtual ~CSetLogoutInfoNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLogoutTime);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLogoutTime);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nRoleID=%d, nLogoutTime=%ld}\n", nRoleID, nLogoutTime);
		offset = (uint32_t) strlen(buf);
	}

public:
	RoleID		nRoleID;
	int64_t		nLogoutTime;
};

//��ʼ�ָ��������
#define MSGID_HSTT_BEGINBUILDPLAYER_NOTI		0x0013040c
class CBeginBuildPlayerNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBeginBuildPlayerNoti()
	{
	}

	virtual ~CBeginBuildPlayerNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nothing}\n");
		offset = (uint32_t) strlen(buf);
	}
};

//���´��������� player��room ����֪ͨ
#define MSGID_HSTS_PLAYERUPDATE_NOTI			0x0013040d

//������������״̬
#define MSGID_HSTT_HALLSERVERISRUNING_NOTI		0x0013040e
class CHallServerIsRuningNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CHallServerIsRuningNoti()
	{
	}

	virtual ~CHallServerIsRuningNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nothing}\n");
		offset = (uint32_t) strlen(buf);
	}
};


//add your message to map
MESSAGEMAP_DECL_BEGIN(hallserver)

MESSAGEMAP_DECL_MSG(MSGID_HSDB_GETROLELOGININFO_REQ, (new CHallGetRoleLoginInfoReq_Public()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_GETROOMINFO_REQ, (new CHallGetRoomInfoReq_Public()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_GETROOM_ADMIN_COUNT_REQ, (new CHallGetRoomAdminCountReq()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_SET_TITLE_REQ, (new CHallSetTitleReq()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_SETSELFINFO_REQ, (new CHallSetSelfInfoReq()))

MESSAGEMAP_DECL_MSG(MSGID_HSTT_BEGINBUILDPLAYER_NOTI, (new CBeginBuildPlayerNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSTS_PLAYERUPDATE_NOTI,(new CUpdateDataNoti()))


MESSAGEMAP_DECL_MSG(MSGID_HSTA_ONLINE_NOTI, (new COnlineNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSTA_OFFLINE_NOTI, (new COfflineNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSRS_SETSELFSETTING_NOTI, (new CHallSetSelfSettingNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSRS_UPDATEGLOBALSTATE_NOTI, (new CHallUpdateGlobalStateNoti()))


MESSAGEMAP_DECL_MSG(MSGID_HSTA_MODIFY_TITLE_NOTIFY, (new CModifyTitleNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_SETLOGININFO_NOTI, (new CSetLoginInfoNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSDB_SETLOGOUTINFO_NOTI, (new CSetLogoutInfoNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSTT_HALLSERVERISRUNING_NOTI, (new CHallServerIsRuningNoti()))

MESSAGEMAP_DECL_MSG(MSGID_HSTS_PLAYERUPDATE_NOTI, (new CUpdateDataNoti()))

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* HALLSERVER_MESSAGE_DEFINE_H_ */
