/*
 * client_message_define.h
 *
 *  Created on: 2013-1-15
 *      Author: jimm
 */

#ifndef CLIENT_MESSAGE_DEFINE_H_
#define CLIENT_MESSAGE_DEFINE_H_

#include "common/common_singleton.h"
#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

//hallserver

//登陆大厅请求
#define MSGID_CLHS_LOGIN_REQ			0x00018001
class CLoginReq : public IMsgBody
{
	SIZE_INTERFACE();

	CLoginReq()
	{
		nAccountType = enmInvalidAccountType;
		nTokenSize = 0;
		memset(arrTokenBuff, 0, sizeof(arrTokenBuff));
		strAccountName.Initialize();
		nRoleID = 0;
		nClientType = 0;
		nClientVersion = 0 ;
		nOSVersion = 0;
		strMacAddr.Initialize();
		nChannel = 0;
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nAccountType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nTokenSize);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, arrTokenBuff, nTokenSize, MaxTokenBuffSize);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strAccountName.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nClientType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nClientVersion);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nOSVersion);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strMacAddr.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nClientVersion >= 1000500)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nChannel);
			if(0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nAccountType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nTokenSize);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, arrTokenBuff, nTokenSize, MaxTokenBuffSize);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strAccountName.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nClientType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nClientVersion);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nOSVersion);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = strMacAddr.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		if(nClientVersion >= 1000500)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nChannel);
			if(0 > nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nAccountType=%d,nTokenSize=%d,strAccountName=%s,nRoleID=%d,nClientType=%d,"
				"nClientVersion=%u,nOSVersion=%u,strMacAddr=%s", nAccountType, nTokenSize, strAccountName.GetString(), nRoleID,
				nClientType, nClientVersion, nOSVersion, strMacAddr.GetString());
		offset = (uint32_t)strlen(buf);
		if(nClientVersion >= 1000500)
		{
			sprintf(buf + offset, ",nChannel=%u}", nChannel);
		}else
		{
			sprintf(buf + offset, "}");
		}
		offset = (uint32_t)strlen(buf);
	}

	AccountType nAccountType;
	uint16_t nTokenSize;
	uint8_t arrTokenBuff[MaxTokenBuffSize];
	CString<MaxAccountName> strAccountName;
	RoleID nRoleID;
	uint8_t nClientType;
	uint32_t nClientVersion;
	uint32_t nOSVersion;
	CString<MaxMacAddrStringLength> strMacAddr;
	uint32_t nChannel;
};

//登陆大厅登出
#define MSGID_CLHS_LOGOUT_REQ			0x00018002
class CLogoutReq : public IMsgBody//, IDumpMsgBody
{
	SIZE_INTERFACE();
public:
	CLogoutReq()
	{
		nLogoutReason = enmLogoutReason_Unknown;
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nLogoutReason);
		if (0 > nRet)
		{
			return nRet;
		}
		return nRet;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nLogoutReason);
		if (0 > nRet)
		{
			return nRet;
		}
		return nRet;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nLogoutReason=%d}", nLogoutReason);
		offset = (uint32_t)strlen(buf);
	}

public:
	LogoutReason nLogoutReason;
};

//增加管理权限请求
#define MSGID_CLHS_ADD_TITLE_REQ		0x00018019
class CAddTitleReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CAddTitleReq()
	{
		nAddRoleRank = enmRoleRank_None;
		nDestRoleID = enmInvalidRoleID;
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nAddRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if (nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nAddRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nDestRoleID);
		if (nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nAddRoleRank=%d,nDestRoleID=%d}",nAddRoleRank ,nDestRoleID );
		offset = (uint32_t)strlen(buf);
	}
public:
	RoleRank nAddRoleRank;
	RoleID nDestRoleID;
};

//删除权限请求
#define MSGID_CLHS_DEL_TITLE_REQ		0x0001801a
class CDelTitleReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CDelTitleReq()
	{
		nDelRoleRank = enmRoleRank_None;
		nDestRoleID = enmInvalidRoleID;
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nDelRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if (nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nDelRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nDestRoleID);
		if (nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{ndelRoleRank=%d,nDestRoleID=%d}",nDelRoleRank ,nDestRoleID );
		offset = (uint32_t)strlen(buf);
	}
public:
	RoleRank nDelRoleRank;
	RoleID nDestRoleID;
};

//设置玩家自身信息的请求
#define MSGID_CLHS_SETSELFINFO_REQ		0x00018004
#define MaxSetSelfInfoCount	16
class CSetSelfInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetSelfInfoReq()
	{
		m_nSetInfoCount = 0;
		memset(m_arrUserInfoType, enmUserInfoType_Invalid, MaxSetSelfInfoCount);
		m_nUserInfoSelfSet = 0;
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, m_nSetInfoCount);
		if(0 > nRet)
		{
			return nRet;
		}
		for(uint8_t i = 0; i < m_nSetInfoCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, m_arrUserInfoType[i]);
			if(0 > nRet)
			{
				return nRet;
			}
			switch(m_arrUserInfoType[i])
			{
				case enmUserInfoType_Self_Setting:
				nRet = CCodeEngine::Decode(buf, size, offset, m_nUserInfoSelfSet);
				if(0 > nRet)
				{
					return nRet;
				}
				break;
				default:
				break;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{m_nSetInfoCount=%d,m_nUserInfoSelfSet=%d}",m_nSetInfoCount,m_nUserInfoSelfSet);
		offset = (uint32_t)strlen(buf);
	}
public:
	uint8_t m_nSetInfoCount;
	UserInfoType m_arrUserInfoType[MaxSetSelfInfoCount];
//	CString<MaxRoleNameLength> m_strUserName ;//string，可修改
//	uint16_t m_nUserBirthdayYear ;//uint16, 可修改
//	uint8_t m_nUserBirthdayMonth ;//uint8, 可修改
//	uint8_t m_nUserBirthdayDay ;//uint8, 可修改
//	CString<enmMaxProvinceNameLength> m_strUserHomeProvince;//string, 可修改
//	CString<enmMaxCityNameLength> m_strUserHomeCity;//string, 可修改
	uint32_t m_nUserInfoSelfSet;//uint32, 可修改

};

//登陆大厅响应
#define MSGID_HSCL_LOGIN_RESP			0x00020401
class CLoginResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}

		if(nResult > 0)
		{

			nRet = strFailReason.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			if(nResult==enmLoginResult_AccountLock || nResult==enmLoginResult_IpLock || nResult==enmLoginResult_MacLock)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, nKickDays);
				if (0 > nRet)
				{
					return nRet;
				}
				nRet = strLockEndDate.MessageEncode(buf, size, offset);
				if (0 > nRet)
				{
					return nRet;
				}
			}
		}
		else
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nLastVersion);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nLastLoginTimeHigh32);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nLastLoginTimeLow32);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSystemTimeHigh32);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSystemTimeLow32);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nGender);
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
			nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nUserLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nOnlineTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nLeftTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nLeftMoney);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nNetType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSelfSetting);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nRmbUserType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nAccountSafeStatus);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nNextLevelNeedMoney);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSelf_business);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	int32_t	MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nResult=%d,", nResult);
	    offset = (uint32_t)strlen(buf);
	    if(nResult > 0)
	    {
	    	sprintf(buf + offset, "strFailReason=%s}", strFailReason.GetString());
	    	if(nResult==enmLoginResult_AccountLock || nResult==enmLoginResult_IpLock || nResult==enmLoginResult_MacLock)
	    	{
	    		offset = (uint32_t)strlen(buf);
	    		sprintf(buf + offset, "nKickDays=%d,strLockEndDate=%s}", nKickDays,strLockEndDate.GetString());
	    	}
	    }
	    else
	    {
	        sprintf(buf + offset, "nLastVersion=%d,nLastLoginTimeHigh32=%d,nLastLoginTimeLow32=%d,"
	        		"nSystemTimeHigh32=%d,nSystemTimeLow32=%d,Gender=%d,strRoleName=%s,nAccountID=%d,nVipLevel=%d"
	        		"nUserLevel=%d,nOnlineTime=%d,nLeftTime=%d,nLeftMoney=%d,nNetType=%d,nSelfSetting=%u,"
	        		"nRmbUserType=%d,nAccountSafeStatus=%d, nMagnateLevel=%d, nNextLevelNeedMoney=%d, nSelf_business=%u}", nLastVersion, nLastLoginTimeHigh32,
	        		nLastLoginTimeLow32, nSystemTimeHigh32, nSystemTimeLow32, nGender, strRoleName.GetString(), nAccountID,
	        		nVipLevel, nUserLevel, nOnlineTime, nLeftTime, nLeftMoney, nNetType, nSelfSetting, nRmbUserType, nAccountSafeStatus,
	        		nMagnateLevel, nNextLevelNeedMoney, nSelf_business);
	    }
	    offset = (uint32_t)strlen(buf);
	}
public:
	uint32_t	nResult;
	CString<MaxLoginFailReasonLength>	strFailReason;
	uint16_t	nKickDays;//表示被踢多少天
	CString<enmMaxDateTimeStringLength> strLockEndDate;//封停截止日期
	uint32_t	nLastVersion;
	uint32_t	nLastLoginTimeHigh32;
	uint32_t	nLastLoginTimeLow32;
	uint32_t	nSystemTimeHigh32;
	uint32_t	nSystemTimeLow32;
	Gender		nGender;
	CString<MaxRoleNameLength>	strRoleName;
	uint32_t	nAccountID;
	VipLevel	nVipLevel;
	UserLevel	nUserLevel;
	uint16_t	nOnlineTime;
	uint16_t	nLeftTime;
	uint32_t	nLeftMoney;
	NetType		nNetType;
	uint32_t	nSelfSetting;
	uint8_t     nRmbUserType;//0为非付费用户，1为付费用户
	uint8_t     nAccountSafeStatus;//0为未设置密保，1为设置了密保
	MagnateLevel nMagnateLevel;            //富豪等级
	uint32_t    nNextLevelNeedMoney;       //到下一级还需要的消费额
	IdentityType nSelf_business;
};

//踢出用户
#define MSGID_HSCL_KICKUSER_NOTI		0x00030405
class CKickUserNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = strReason.MessageEncode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		if(enmKickReason_PlayerLock==nResult || enmKickReason_IPLock==nResult || enmKickReason_MacLock==nResult)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nKickDays);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = strLockEndDate.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	int32_t	MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nResult=%d,strKickReason=%s", nResult, strReason.GetString());
	    offset = (uint32_t)strlen(buf);
	    if(enmKickReason_PlayerLock==nResult || enmKickReason_IPLock==nResult || enmKickReason_MacLock==nResult)
	    {
	    	sprintf(buf + offset, ",nKickDays=%d,nLockEndDate=%s}", nKickDays, strLockEndDate.GetString());
			offset = (uint32_t)strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	KickReason	nResult;
	CString<MaxKickPlayerReasonLength>	strReason;
	uint16_t	nKickDays;//表示被踢多少天
	CString<enmMaxDateTimeStringLength> strLockEndDate;
};

//增加管理权限响应
#define MSGID_HSCL_ADD_TITLE_RESP		0x00020719
class CAddTitleResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nChangeResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nChangeResult=%d}", nChangeResult);
		offset = (uint32_t)strlen(buf);
	}
public:
	ChangeResult nChangeResult;
};

//增加管理权限通知(to client)
#define MSGID_HSCL_ADD_TITLE_NOTI		0x00030719
class CAddtitleNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nAddRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSrcRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nAddRoleRank=%d,nSrcRoleID=%d,nDestRoleID=%d}",nAddRoleRank,nSrcRoleID,nDestRoleID);
		offset = (uint32_t) strlen(buf);
	}
public:
	RoleRank  nAddRoleRank;
	RoleID    nSrcRoleID;
	RoleID    nDestRoleID;
};

//删除权限响应
#define MSGID_HSCL_DEL_TITLE_RESP		0x0002071a
class CDelTitleResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nChangeResult);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nChangeResult=%d}", nChangeResult);
		offset = (uint32_t)strlen(buf);
	}
public:
	ChangeResult nChangeResult;
};

//删除权限通知(to client)
#define MSGID_HSTA_DEL_TITLE_NOTIFY		0x0003071a
class CDelTitleNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nDelRoleRank);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nSrcRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nDelRoleRank=%d,nSrcRoleID=%d,nDestRoleID=%d", nDelRoleRank, nSrcRoleID, nDestRoleID);
		offset = (uint32_t) strlen(buf);
	}
public:
	RoleRank	nDelRoleRank;
	RoleID		nSrcRoleID;
	RoleID		nDestRoleID;
};

//设置玩家自身信息的响应
#define MSGID_HSCL_SETSELFINFO_RESP 	0x00020404
class CSetSelfInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nSetSelfInfoResult);
		if(0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nSetSelfInfoResult=%d}", nSetSelfInfoResult);
		offset = (uint32_t)strlen(buf);
	}
public:
	uint32_t nSetSelfInfoResult;
};

//更新玩家昵称和性别通知
#define MSGID_HSCL_UPDATEUSERINFONOTI	0x00030408
class CUpdateUserInfoNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strRoleName.MessageEncode(buf, size, offset);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGender);
		if(0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strRoleName=%s,nGender=%d}", strRoleName.GetString(), nGender);
		offset = (uint32_t)strlen(buf);
	}
public:
	CString<MaxRoleNameLength>		strRoleName;
	Gender							nGender;
};


//add your message to map


//itemserver

//roomserver
//客户端获取离线主播列表





//taskserver

//领取奖励请求
#define MSGID_CLTK_GETREWARD_REQ     0x00018034
class CGetRewardReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	TaskID         nTaskID;
	CGetRewardReq()
	{
		nTaskID = 0;
	}
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nTaskID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nTaskID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nTaskID=%d}", nTaskID);
		offset = (uint32_t)strlen(buf);
	}
};

#define TASK_UPDATE_STATE_NOTICE    0x00030733

class CUpdateTaskInfoNotice : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t		MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for(int32_t i = 0 ;i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrTaskID[ i ]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrTaskType[ i ]);
			if (0 > nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	int32_t		MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void		Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{ nCount=%d, ", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "{TaskID=%d, TaskStat=%d} ", arrTaskID[ i ],arrTaskType[ i ]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "} ");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t          nCount;                        //更新任务数
	TaskID           arrTaskID[MAX_TASK_COUNT];
	TaskStatType     arrTaskType[MAX_TASK_COUNT];
};

#define MSGID_CLTK_GETREWARD_RESQ    0x00020734
class CGetRewardResp:public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t         nResult ;
	CGetRewardResp()
	{
		nResult = 0;
	}
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

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}", nResult);
		offset = (uint32_t)strlen(buf);
	}
};

//sysinfoserver
//系统公告响应




MESSAGEMAP_DECL_BEGIN(client_message)

MESSAGEMAP_DECL_MSG(MSGID_CLTK_GETREWARD_REQ, (new CGetRewardReq()))


MESSAGEMAP_DECL_MSG(MSGID_CLHS_LOGIN_REQ, (new CLoginReq()))

MESSAGEMAP_DECL_MSG(MSGID_CLHS_LOGOUT_REQ, (new CLogoutReq()))

MESSAGEMAP_DECL_MSG(MSGID_CLHS_ADD_TITLE_REQ, (new CAddTitleReq()))

MESSAGEMAP_DECL_MSG(MSGID_CLHS_DEL_TITLE_REQ, (new CDelTitleReq()))

MESSAGEMAP_DECL_MSG(MSGID_CLHS_SETSELFINFO_REQ, (new CSetSelfInfoReq()))

MESSAGEMAP_DECL_MSG(MSGID_CLTK_GETREWARD_REQ, (new CGetRewardReq()))

MESSAGEMAP_DECL_MSG(TASK_UPDATE_STATE_NOTICE, (new CUpdateTaskInfoNotice()))

MESSAGEMAP_DECL_MSG(MSGID_CLTK_GETREWARD_RESQ, (new CGetRewardResp()))


MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END



#endif /* CLIENT_MESSAGE_DEFINE_H_ */
