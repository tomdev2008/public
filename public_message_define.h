/*
 * public_message_define.h
 *
 *  Created on: 2012-2-9
 *      Author: jimm
 */

#ifndef PUBLIC_MESSAGE_DEFINE_H_
#define PUBLIC_MESSAGE_DEFINE_H_

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
//#include "frame/impl/frame_protocol_impl.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include <stdio.h>
#include <string.h>

FRAME_NAMESPACE_BEGIN

enum
{
	enmMaxSerialNumberLength		= 40,	//流水号最大长度
	enmMaxTimeStringLength			= 128,	//最大时间描述字符串
};
#define MSGID_OTDB_UPDATEASSET_REQ					0x0011ff01
class CUpdateAssetReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateAssetReq()
	{
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nCauseID = enmInvalidCauseID;
		nUpdateCount = 0;
		nMagnateLevel = enmMagnateLevel_0;
		nSpendMoneySum = 0;
		nNextLevelSpend = 0;
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}
	virtual ~CUpdateAssetReq()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strTransID.MessageEncode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCauseID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSpendMoneySum);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nNextLevelSpend);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrAssetType[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateAssetOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrAssetValue[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strTransID.MessageDecode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCauseID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMagnateLevel);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSpendMoneySum);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nNextLevelSpend);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrAssetType[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateAssetOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrAssetValue[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strTransID=%s,nRoleID=%d,nCauseID=%d,nMagnateLevel=%d,nSpendMoneySum=%lu,nNextLevelSpend=%lu,nUpdateCount=%d,arrAssetType={",
				strTransID.GetString(), nRoleID, nCauseID, nMagnateLevel, nSpendMoneySum, nNextLevelSpend, nUpdateCount);
	    offset = (uint32_t)strlen(buf);
	    if(nUpdateCount > 0)
	    {
	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%u, ", arrAssetValue[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%u}}", arrAssetValue[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "},arrUpdateAssetOperate={},arrAssetValue={}}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID			nRoleID;
	CauseID			nCauseID;
	int32_t			nUpdateCount;
	MagnateLevel	nMagnateLevel;	//富豪等级
	uint64_t		nSpendMoneySum;	//消费总额
	uint64_t		nNextLevelSpend;//下一个等级的消费额
	AssetType		arrAssetType[MaxUpdateAssetCount];
	UpdateAssetOperate	arrUpdateAssetOperate[MaxUpdateAssetCount];
	uint32_t		arrAssetValue[MaxUpdateAssetCount];
};

#define MSGID_DBOT_UPDATEASSET_RESP					0x0012ff01
class CUpdateAssetResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateAssetResp()
	{
		nResult = 0;
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nCauseID = enmInvalidCauseID;
		nUpdateCount = 0;
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}
	virtual ~CUpdateAssetResp()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == S_OK)
		{
			nRet = strTransID.MessageEncode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nCauseID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nUpdateCount);
			if(nRet < 0)
			{
				return nRet;
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrAssetType[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateAssetOperate[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrAssetValue[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == S_OK)
		{
			nRet = strTransID.MessageDecode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nCauseID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nUpdateCount);
			if(nRet < 0)
			{
				return nRet;
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrAssetType[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateAssetOperate[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrAssetValue[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nReuslt=%d", nResult);
	    offset = (uint32_t)strlen(buf);
	    if(nResult == S_OK)
	    {
			sprintf(buf + offset, ",strTransID=%s,nRoleID=%d,nCauseID=%d,nUpdateCount=%d,arrAssetType={",
					strTransID.GetString(), nRoleID, nCauseID, nUpdateCount);
		    offset = (uint32_t)strlen(buf);
		    if(nUpdateCount > 0)
		    {
		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%d},arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);

		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%d},arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);

		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%u, ", arrAssetValue[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%u}}", arrAssetValue[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);
		    }
		    else
		    {
		    	sprintf(buf + offset, "},arrUpdateAssetOperate={},arrAssetValue={}}");
		    	offset = (uint32_t)strlen(buf);
		    }
	    }
	    else
	    {
	    	sprintf(buf + offset, "}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	int32_t			nResult;
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID			nRoleID;
	CauseID			nCauseID;
	int32_t			nUpdateCount;
	AssetType		arrAssetType[MaxUpdateAssetCount];
	UpdateAssetOperate	arrUpdateAssetOperate[MaxUpdateAssetCount];
	uint32_t		arrAssetValue[MaxUpdateAssetCount];
};

/*
* 协议描述：后台更新用户资产通知
*/
#define MSGID_WEBAGENTTO_UPDATEASSET_NOTI  			0x0013ff02
class CPubWebUpdateAssetNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;                          //179uin
	AssetUpdateMode  nUpdateMode;            //更新模式：增加或者减少, 1增加，2减少
	int32_t nMoneyAmount;                    //更新数量
	AssetUpdateChannel nUpdateChannel;       //更新渠道：0无效， 1：充值， 2：运营人员给玩家加钱
	CString<enmMaxTimeStringLength>    strDateTime;  //datetime类型，如2012-08-03 12:00:00	
	int32_t nSongRequest;     //点歌小七的数量
	int32_t nRedFlower;        //小红花的数量
	CString<MaxAssetUpdateReasonLength>  strReason;  //资产更新原因

public:
	CPubWebUpdateAssetNoti()
	{
		nRoleID = enmInvalidRoleID;
		nUpdateMode = enmAssetUpdateMode_None;
		nMoneyAmount = 0;
		nUpdateChannel = 0;
		strDateTime.Initialize();
		nSongRequest = 0;
		nRedFlower = 0;
		strReason.Initialize();
	}
	virtual ~CPubWebUpdateAssetNoti(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUpdateMode);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMoneyAmount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nUpdateChannel);
		if(0 > ret)
		{
			return ret;
		}
		ret = strDateTime.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nSongRequest);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRedFlower);
		if(0 > ret)
		{
			return ret;
		}
		ret = strReason.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUpdateMode);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMoneyAmount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nUpdateChannel);
		if(0 > ret)
		{
			return ret;
		}
		ret = strDateTime.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nSongRequest);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRedFlower);
		if(0 > ret)
		{
			return ret;
		}
		ret = strReason.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return S_OK;//暂时PHP没有加入这个字段
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "web update user asset notice:{nRoleID=%d, nUpdateMode=%d, nMoneyAmount=%d, updateChannle=%d, strDateTime=%s, nSongReq=%d, nRedFlower=%d, strReason=%s}\n",
			nRoleID, nUpdateMode, nMoneyAmount, nUpdateChannel, strDateTime.GetString(), nSongRequest, nRedFlower, strReason.GetString());
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_OTIS_UPDATEUSERASSET_REQ				0x0011ff03
class CUpdateUserAssetReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateUserAssetReq()
	{
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nCauseID = enmInvalidCauseID;
		nUpdateCount = 0;
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}
	virtual ~CUpdateUserAssetReq()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strTransID.MessageEncode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCauseID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrAssetType[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateAssetOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrAssetValue[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strTransID.MessageDecode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCauseID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrAssetType[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateAssetOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrAssetValue[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strTransID=%s,nRoleID=%d,nCauseID=%d,nUpdateCount=%d,arrAssetType={",
				strTransID.GetString(), nRoleID, nCauseID, nUpdateCount);
	    offset = (uint32_t)strlen(buf);
	    if(nUpdateCount > 0)
	    {
	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d},arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%u, ", arrAssetValue[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%u}}", arrAssetValue[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "},arrUpdateAssetOperate={},arrAssetValue={}}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID			nRoleID;
	CauseID			nCauseID;
	int32_t			nUpdateCount;
	AssetType		arrAssetType[MaxUpdateAssetCount];
	UpdateAssetOperate	arrUpdateAssetOperate[MaxUpdateAssetCount];
	uint32_t		arrAssetValue[MaxUpdateAssetCount];
};


#define MSGID_ISOT_UPDATEUSERASSET_RESP					0x0012ff03
class CUpdateUserAssetResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateUserAssetResp()
	{
		nResult = 0;
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nCauseID = enmInvalidCauseID;
		nUpdateCount = 0;
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}
	virtual ~CUpdateUserAssetResp()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == enmUpdateUserAsset_OK)
		{
			nRet = strTransID.MessageEncode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nCauseID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nUpdateCount);
			if(nRet < 0)
			{
				return nRet;
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrAssetType[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateAssetOperate[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrAssetValue[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult == enmUpdateUserAsset_OK)
		{
			nRet = strTransID.MessageDecode(buf, size, offset);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nCauseID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nUpdateCount);
			if(nRet < 0)
			{
				return nRet;
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrAssetType[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateAssetOperate[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
			for(int32_t i = 0; i < nUpdateCount; ++i)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrAssetValue[i]);
				if(nRet < 0)
				{
					return nRet;
				}
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nReuslt=%d", nResult);
	    offset = (uint32_t)strlen(buf);
	    if(nResult == enmUpdateUserAsset_OK)
	    {
			sprintf(buf + offset, ",strTransID=%s,nRoleID=%d,nCauseID=%d,nUpdateCount=%d,arrAssetType={",
					strTransID.GetString(), nRoleID, nCauseID, nUpdateCount);
		    offset = (uint32_t)strlen(buf);
		    if(nUpdateCount > 0)
		    {
		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%d},arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);

		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%d},arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);

		    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
		    	{
		    		sprintf(buf + offset, "%u, ", arrAssetValue[i]);
		    		offset = (uint32_t)strlen(buf);
		    	}
		    	sprintf(buf + offset, "%u}}", arrAssetValue[nUpdateCount - 1]);
		    	offset = (uint32_t)strlen(buf);
		    }
		    else
		    {
		    	sprintf(buf + offset, "},arrUpdateAssetOperate={},arrAssetValue={}}");
		    	offset = (uint32_t)strlen(buf);
		    }
	    }
	    else
	    {
	    	sprintf(buf + offset, "}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	UpdateUserAsset	nResult;
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID			nRoleID;
	CauseID			nCauseID;
	int32_t			nUpdateCount;
	AssetType		arrAssetType[MaxUpdateAssetCount];
	UpdateAssetOperate	arrUpdateAssetOperate[MaxUpdateAssetCount];
	uint32_t		arrAssetValue[MaxUpdateAssetCount];
};

class BasicNotifyInfo
{
	SIZE_INTERFACE();
public:
	CString<MaxInfoSize> 		strMessage;
	BasicNotifyInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		strMessage.Initialize();
	}
};

class NotifyInfo : public BasicNotifyInfo
{
	SIZE_INTERFACE();
public:
	CString<MaxInfoSize> 		strText;
	CString<MaxInfoSize> 		strUrl;
	NotifyInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		BasicNotifyInfo::Initialize();
		strText.Initialize();
		strUrl.Initialize();
	}
};

class BasicUpdateClientVipLevelInfo
{
	SIZE_INTERFACE();
public:
	uint8_t		nType;
	uint8_t		nVipLevel;
	BasicUpdateClientVipLevelInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nType = 0;
		nVipLevel = 0;
	}
};

// sys notify message to client
#define MSGID_SSCL_SYSINFO_Noti						0x00030406
class CSysNoti_Public : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t		MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nType);
		if(0>nRet)
		{
			return nRet;
		}
		nRet = strTitle.MessageEncode(buf, size, offset);
		if(0>nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0>nRet)
		{
			return nRet;
		}
		for(uint8_t i = 0; i < nCount; i++)
		{
			nRet = arrNotifyInfos[i].strMessage.MessageEncode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
			nRet = arrNotifyInfos[i].strText.MessageEncode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
			nRet = arrNotifyInfos[i].strUrl.MessageEncode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	int32_t		MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf,  size, offset, nType);
		if(0>nRet)
		{
			return nRet;
		}
		nRet = strTitle.MessageDecode(buf, size, offset);
		if(0>nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf,  size, offset, nCount);
		if(0>nRet)
		{
			return nRet;
		}
		for(uint8_t i = 0; i < nCount; i++)
		{
			nRet = arrNotifyInfos[i].strMessage.MessageDecode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
			nRet = arrNotifyInfos[i].strText.MessageDecode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
			nRet = arrNotifyInfos[i].strUrl.MessageDecode(buf, size, offset);
			if(0>nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void		Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{nType=%u,strTitle=%s\n", nType, strTitle.GetString());
	    offset = (uint32_t)strlen(buf);
	    sprintf(buf + offset, "nCount=%d\n", nCount);
	    offset = (uint32_t)strlen(buf);
		for(uint8_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "\arrNotifyInfos[%u].strMessage=[%s]\nstrText=[%s]\nstrUrl=[%s]\n",
					i, arrNotifyInfos[i].strMessage.GetString(),
					arrNotifyInfos[i].strText.GetString(),
					arrNotifyInfos[i].strUrl.GetString());
			 offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}\n");
		offset = (uint32_t)strlen(buf);
	}
	CSysNoti_Public()
	{
		nType = enumSYSTEMMESSAGETYPE_INVALID;
		strTitle.Initialize();
		nCount = 0;
		for(int32_t i = 0; i < MaxNotiCount; i++)
		{
			arrNotifyInfos[i].Initialize();
		}
	}
	~CSysNoti_Public(){}
public:
	ENM_SystemMessageType	nType;
	CString<MaxTitleSize> 	strTitle;
	uint8_t					nCount;
	NotifyInfo				arrNotifyInfos[MaxNotiCount];
};

// 更新客户端玩家Vip等级
#define MSGID_SSCL_UPDATEVIPLEVEL_NOTI				0x00030404
class CUpdateClientVipLevelNotify	: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t		MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > nRet)
		{
			return nRet;
		}
		for(uint8_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrVipInfo[i].nType);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrVipInfo[i].nVipLevel);
			if(0 > nRet)
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
	    sprintf(buf + offset, "{nCount=%d}\n", nCount);
	    offset = (uint32_t)strlen(buf);
	    for(uint8_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "\arrVipInfo[%u].nType=[%u]\nVipLevel=[%u]\n",
					i, arrVipInfo[i].nType,
					arrVipInfo[i].nVipLevel);
			 offset = (uint32_t)strlen(buf);
		}
	}
	CUpdateClientVipLevelNotify()
	{
		nCount = 0;
		for(int32_t i = 0; i < UserCountEveryTime; i++)
		{
			arrVipInfo[i].Initialize();
		}
	}
	~CUpdateClientVipLevelNotify(){}
public:
	uint8_t 	nCount;
	BasicUpdateClientVipLevelInfo	arrVipInfo[UserCountEveryTime];
};

// room public notify message
#define MSGID_SSCL_ROOM_Noti						0x0003072A
class CRoomPublicNotice : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t		MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strMessage.MessageEncode(buf, size, offset);
		if(0>nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t		MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = strMessage.MessageDecode(buf, size, offset);
		if(0>nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void		Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
	    sprintf(buf + offset, "{strMessage=%s}\n", strMessage.GetString());
	    offset = (uint32_t)strlen(buf);
	}
	CRoomPublicNotice()
	{
		strMessage.Initialize();
	}
	~CRoomPublicNotice(){}
public:
	CString<MaxInfoSize> 	strMessage;
};

// update viplevel notify to other servers
#define MSGID_SSRS_UPDATELEVEL_NOTI					0x0013ff07
class CUpdateVipLevelNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPreVipLevel);
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
		if(0>nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if(0>nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nPreVipLevel);
		if(0>nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{this is the update viplevel notify msgbody: nRoleID=%d, nVipLevel=%u, nPreVipLevel=%u\n}",
				nRoleID, nVipLevel, nPreVipLevel);
	    offset = (uint32_t)strlen(buf);
	}
public:
	CUpdateVipLevelNotify()
	{
		nRoleID = enmInvalidRoleID;
		nVipLevel = enmInvalidVipLevel;
		nPreVipLevel = enmInvalidVipLevel;
	}
	virtual ~CUpdateVipLevelNotify(){}

public:
	RoleID		nRoleID;
	VipLevel	nVipLevel;		//新的VIP等级
	VipLevel	nPreVipLevel;	//前次VIP等级
};

// update pwd status notify
#define MSGID_SSCL_UPDATEPWDSTATUS_NOTI				0x00030407
class CUpdatePWDStatusNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{this is the update pwd status notification\n}");
	    offset = (uint32_t)strlen(buf);
	}
public:
	CUpdatePWDStatusNotify()
	{}
	virtual ~CUpdatePWDStatusNotify(){}
};

#define MSGID_WEBOT_UPDATE_USERDATA_NOTI     0x0013FF08
class CPupUpdateUserDataNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;
public:
	CPupUpdateUserDataNoti()
	{
		nRoleID = enmInvalidRoleID;
	}
	virtual ~CPupUpdateUserDataNoti(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d\n", nRoleID);
		offset = (uint32_t)strlen(buf);
	}
};

//web发送封玩家通知给hallserver
#define MSGID_DBHS_LOCKPLAYER_NOTIFY	0x0013FF09
class CLockPlayerNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CLockPlayerNotify()
	{
		nDestRoleID = enmInvalidRoleID;
		nTimeLock = 0;
		nTimeUnlock = 0;
		strLockPlayerReason.Initialize();
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nDestRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTimeLock);
		if (0 > ret) {
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}

		ret = strLockPlayerReason.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nDestRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTimeLock);
		if (0 > ret) {
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}

		ret = strLockPlayerReason.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "LockPlayer:nDestRoleID=%d,nTimeUnlock=%lu,nTimeUnlock=%lu\n"
				"Reason is:%s\n", nDestRoleID,nTimeLock, nTimeUnlock, strLockPlayerReason.GetString());
		offset = (uint32_t)strlen(buf);
	}

public:
	RoleID  nDestRoleID;
	uint64_t nTimeLock;
	uint64_t nTimeUnlock;
	CString<MaxLockPlayerReasonLength> strLockPlayerReason;
};

//修改房间类型，目前房间类型包括3种：唱歌，跳舞，聊吧
#define MSGID_WEBOT_MODIFY_ROOMTTYPE_NOTIFY     0x0013FF0A
class CModifyRoomTypeNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;

public:
	CModifyRoomTypeNotify()
	{
		nRoomID = enmInvalidRoomID;
	}
	virtual ~CModifyRoomTypeNotify(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}

		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d", (int32_t)nRoomID);
		offset = (uint32_t)strlen(buf);
	}
};

//房间封停通知
#define MSGID_WEBOT_LOCKROOM_NOTIFY     0x0013FF0B
class CLockRoomNoitfy : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;
	RoleID  nRoomHostRoleID;   //房间室主的roleid
	uint64_t nTimeLock;        //被封的开始时间
	uint64_t nTimeUnlock;      //被封的结束时间
	CString<MaxLockRoomReasonLength> strLockRoomReason;
public:
	CLockRoomNoitfy()
	{
		nRoomID = enmInvalidRoomID;
		nRoomHostRoleID = enmInvalidRoleID;
		nTimeLock = 0 ;
		nTimeUnlock = 0;
		strLockRoomReason.Initialize();
	}
	virtual ~CLockRoomNoitfy(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomHostRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTimeLock);
		if (0 > ret) {
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLockRoomReason.MessageEncode(buf, size, offset);
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
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomHostRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTimeLock);
		if (0 > ret) {
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTimeUnlock);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLockRoomReason.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, nRoomHostRoleID=%d, nTimeLock=%d,nTimeUnlock=%d, strLockRoomReason=%s\n",
			(int32_t)nRoomID, (int32_t)nRoomHostRoleID, (int32_t)nTimeLock, (int32_t)nTimeUnlock, strLockRoomReason.GetString());

		offset = (uint32_t)strlen(buf);
	}
};

//修改房间的容量
#define MSGID_WEBOT_MODIFY_ROOMCAPACITY_NOTIFY    0x0013FF0C
class CModifyRoomCapacityNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID   nRoomID;                //房间号
	int32_t  nRoomHostRoleID;        //房间室主的RoleID
	int32_t  nRoomShowCapacity;      //房间显示容量
	int32_t  nRoomRealCapacity;      //房间实际容量
public:
	CModifyRoomCapacityNotify()
	{
		nRoomID = enmInvalidRoomID;
		nRoomHostRoleID = enmInvalidRoleID;
		nRoomShowCapacity = 0;
		nRoomRealCapacity = 0;
	}
	virtual ~CModifyRoomCapacityNotify(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomHostRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomShowCapacity);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomRealCapacity);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomHostRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomShowCapacity);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoomRealCapacity);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, nRoomHostRoleID=%d, nRoomShowCapacity=%d, nRoomRealCapacity=%d\n", 
			(int32_t)nRoomID, (int32_t)nRoomHostRoleID,(int32_t)nRoomShowCapacity, (int32_t)nRoomRealCapacity);
		offset = (uint32_t)strlen(buf);
	}
};

//批量修改房间管理员的权限
#define   MSGID_WEBOT_BATCH_MODIFY_ROLERANK_NOTIFY      0x0013FF0D
class CBatchModifyRoomRoleRankNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID nRoomID;
//	RoleID  nRoomHostRoleID;
	int32_t nUserCount;       //更新了多少个人的管理员权限
	RoleID  arrRoleID[MaxAdminCountPerRoom];  //这些管理员的179uin
	RoleRank  arrPreRoleRank[MaxAdminCountPerRoom]; //更新之前的管理员权限
	RoleRank  arrNowRoleRank[MaxAdminCountPerRoom];  //更新后的管理员权限(也就是现在的管理员权限)， 如果是删除，则将权限设置为enmRoleRank_None
public:
	CBatchModifyRoomRoleRankNotify()
	{
		nRoomID = enmInvalidRoomID;
		//nRoomHostRoleID = enmInvalidRoleID;
		nUserCount = 0;
		memset(arrRoleID, 0, sizeof(arrRoleID));
		memset(arrPreRoleRank, 0, sizeof(arrPreRoleRank));
		memset(arrNowRoleRank, 0, sizeof(arrNowRoleRank));
	}
	virtual ~CBatchModifyRoomRoleRankNotify(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		//ret = CCodeEngine::Encode(buf, size, offset, nRoomHostRoleID);
		//if(0 > ret)
		//{
		//	return ret;
		//}
		ret = CCodeEngine::Encode(buf, size, offset, nUserCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nUserCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrPreRoleRank[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrNowRoleRank[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		//ret = CCodeEngine::Decode(buf, size, offset, nRoomHostRoleID);
		//if(0 > ret)
		//{
		//	return ret;
		//}
		ret = CCodeEngine::Decode(buf, size, offset, nUserCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nUserCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrPreRoleRank[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrNowRoleRank[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;		
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, nUserCount=%d\n", (int32_t)nRoomID, nUserCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i=0; i<nUserCount; ++i)
		{
			sprintf(buf + offset, "arrRoleID[%d]=%d, arrPreRoleRank[%d]=%d, arrNowRoleRank[%d]=%d\n", 
				i, arrRoleID[i], i, (int32_t)arrPreRoleRank[i], i, (int32_t)arrNowRoleRank[i]);
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);
	}
};

//开通房间通知
#define MSGID_WEBOT_LAUNCHROOM_NOTICE      0x0013FF0E
class CLauchRoomNotice: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID nRoomID;      //开通的房间的房间号
	RoleID nRoleID;      //室主的roleid
	CString<MaxLaunchRoomNoticeLength> strLaunchRoomNotice;  //开通房间提示内容
public:
	CLauchRoomNotice()
	{
		nRoomID = enmInvalidRoomID;
		nRoleID = enmInvalidRoleID;
		strLaunchRoomNotice.Initialize();
	}
	virtual ~CLauchRoomNotice(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLaunchRoomNotice.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strLaunchRoomNotice.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, nRoleID=%d, strLaunchRoomNotice=%s\n", (int32_t)nRoomID, nRoleID, strLaunchRoomNotice.GetString());
		offset = (uint32_t)strlen(buf);
	}
};

//房间名审核通过通知（运营后台修改房间名成功）
#define MSGID_WEBOT_AUDIT_ROOMNAME_NOTIFY        0x0013FF0F
class CAuditRoomNameNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;                           //房间号
	CString<MaxRoomNameLength>  strRoomName;   //修改后的房间名
public:
	CAuditRoomNameNotify()
	{
		nRoomID = enmInvalidRoomID;
		strRoomName.Initialize();
	}
	virtual ~CAuditRoomNameNotify(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoomName.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoomName.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d, strRoomName=%s\n", 
			(int32_t)nRoomID, strRoomName.GetString());
		offset = (uint32_t)strlen(buf);
	}
};

//通知房间礼物之星
#define MSGID_SYRS_GIFT_STAR_NOTIFY        0x00030409
class CGiftStarNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	uint16_t						nGiftStarCount;
	RoleID  						arrGiftRoleID[MaxGiftStarCount];   //用户roleid
	ItemID	  						arrGiftItemID[MaxGiftStarCount];   //礼物id
	uint32_t 						arrGiftCount[MaxGiftStarCount];    //该礼物的数量

public:
	CGiftStarNotify()
	{
		nGiftStarCount = 0;
		memset(arrGiftRoleID,0,sizeof(arrGiftRoleID));
		memset(arrGiftItemID,0,sizeof(arrGiftItemID));
		memset(arrGiftCount,0,sizeof(arrGiftCount));
	}
	virtual ~CGiftStarNotify(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nGiftStarCount);
		if(0 > ret)
		{
			return ret;
		}
		if(nGiftStarCount>MaxGiftStarCount)
		{
			return ENCODE_DECODE_FILED;
		}
		for(int32_t i =0 ;i<nGiftStarCount;i++)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrGiftRoleID[i]);
			if (0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrGiftItemID[i]);
			if (0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrGiftCount[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nGiftStarCount);
		if (0 > ret)
		{
			return ret;
		}
		if (nGiftStarCount > MaxGiftStarCount)
		{
			return ENCODE_DECODE_FILED;
		}
		for (int32_t i = 0; i < nGiftStarCount; i++)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrGiftRoleID[i]);
			if (0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrGiftItemID[i]);
			if (0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrGiftCount[i]);
			if (0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nGiftStarCount=%d\n",
				nGiftStarCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i =0 ;i<nGiftStarCount;i++)
		{
			sprintf(buf + offset, ",%d,0x%08x,%u", arrGiftRoleID[i],arrGiftItemID[i],arrGiftCount[i]);
			offset = (uint32_t) strlen(buf);
		}
	}
};

/*用户密保状态改变通知*/
#define MSGID_WEBOT_PWDPRO_STATUSCHANGE_NOTIFY   0x0013FF11
class CPwdProStatusChangeNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID       nRoleID;   //用户179uin
	PwdProStatus nCurPwdProStatus;   //改变后的密保状态

public:
	CPwdProStatusChangeNoti()
	{
		nRoleID = enmInvalidRoleID;
		nCurPwdProStatus = 0;
	}
	virtual ~CPwdProStatusChangeNoti(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nCurPwdProStatus);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nCurPwdProStatus);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d, nCurPwdProStatus=%d\n", nRoleID, nCurPwdProStatus);
		offset = (uint32_t)strlen(buf);
	}
};

/*进入储备池的比率发生改变通知*/
#define MSGID_WEBOT_STOREPOOL_RATIOCHANGE_NOTIFY   0x0013FF12
class CStorePoolRatioChangeNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	ItemID  nItemID;     //物品的ID， uint16
	int32_t nStartTime;  //比率调整开始的时刻
	int32_t nEndTime;    //比率调整结束的时刻
	int32_t nPreRatio;   //调整之前的储备比率， 如20%的钱流入储备池，则该值为20
	int32_t nNowRatio;   //调整之后的储备比率，如40%， 则该值为40

public:
	CStorePoolRatioChangeNotify()
	{
		nItemID = enmInvalidItemID;
		nStartTime = 0;
		nEndTime = 0;
		nPreRatio = 0;
		nNowRatio = 0;
	}
	virtual ~CStorePoolRatioChangeNotify(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPreRatio);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nNowRatio);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nStartTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPreRatio);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nNowRatio);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nItemID=0x%08x, nStartTime=%d, nEndTime=%d, nPreRatio=%d, nNowRatio=%d\n}\n", 
			nItemID, nStartTime, nEndTime, nPreRatio, nNowRatio);
		offset = (uint32_t)strlen(buf);
	}
};

/*奖池补给速度改变通知*/
#define MSGID_WEBOT_SUPPLYSPEED_CHANGE_NOTIFY     0x0013FF13
class  CSupplySpeedChangeNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	ItemID  nItemID;  //物品ID
	int32_t nAmount;       //补给的数量（单位：币）
	int32_t nMultiple;     //补入奖池的倍数，如10， 50， 500等等

public:
	CSupplySpeedChangeNotify()
	{
		nItemID = enmInvalidItemID;
		nAmount = 0;
		nMultiple = 0;
	}
	virtual ~CSupplySpeedChangeNotify(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMultiple);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMultiple);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nItemID=%x, nAmount=%d, nMultiple=%d\n",
			nItemID, nAmount, nMultiple);
		offset = (uint32_t)strlen(buf);
	}
};

/* 运营人员从储备池拿钱通知 */
#define MSGID_WEBOT_FETCHMONEY_FROM_STOREPOOL_REQ   0x0011FF14
class CFetchMoneyFromStorePoolReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID  nRoleID;    //玩家的179uin
	int32_t nAmount;    //请求拿钱的数量

public:
	CFetchMoneyFromStorePoolReq()
	{
		nRoleID = enmInvalidRoleID;
		nAmount = 0;
	}
	virtual ~CFetchMoneyFromStorePoolReq(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoleID=%d, nAmount=%d\n", 
			nRoleID, nAmount);
		offset = (uint32_t)strlen(buf);
	}
};

/* 运营人员修改中奖比例通知 */
#define MSGID_WEBOT_SETRATIO_JACKPOT_NOTIFY   0x0011FF15
class CSetJackpotRatioNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	nItemID;    //道具ID
	int32_t nCount;   //奖池个数
	int32_t	nMultipe[MaxJackpotCountPerLuckyItem];   //奖池倍数
	int32_t	nRatio[MaxJackpotCountPerLuckyItem];    //进入此倍数奖池的钱币比列
	int32_t nProbability[MaxJackpotCountPerLuckyItem];//中此倍数的概率
	int8_t	nFlag[MaxJackpotCountPerLuckyItem];		//0表示用奖池模式，1表示用概率模式

public:
	CSetJackpotRatioNotify()
	{
		nItemID = 0;
		nCount = 0;
		memset(nMultipe, 0, MaxJackpotCountPerLuckyItem);
		memset(nRatio, 0, MaxJackpotCountPerLuckyItem);
		memset(nProbability, 0, MaxJackpotCountPerLuckyItem);
		memset(nFlag, 0, MaxJackpotCountPerLuckyItem);
	}
	virtual ~CSetJackpotRatioNotify(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int i = 0; i < nCount; i++)
		{
			ret = CCodeEngine::Encode(buf, size, offset, nMultipe[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, nRatio[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, nProbability[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, nFlag[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int i = 0; i < nCount; i++)
		{
			ret = CCodeEngine::Decode(buf, size, offset, nMultipe[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, nRatio[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, nProbability[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, nFlag[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nItemID=0x%04x, nCount=%d{",	nItemID, nCount);
		offset = (uint32_t)strlen(buf);
		for(int i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "nMultipe=%d, nRatio=%d, nProbability=%d, nFlag=%d; ",
					nMultipe[i], nRatio[i], nProbability[i], nFlag[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}\n");
		offset = (uint32_t)strlen(buf);
	}
};

/* 运营人员从储备池拿钱响应 */
#define MSGID_BSWEB_FETCHMONEY_FROM_STOREPOOL_RESP    0x0012FF14
class CFetchMoneyFromStorePoolResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;      //返回值，0为正常，小于0标示出错（如数据库操作失败等）
	int32_t nRealAmount;  //实际拿钱的数量（因有可能请求中的数量大于储备池中的剩余数量）
public:
	CFetchMoneyFromStorePoolResp()
	{
		nResult = 0;
		nRealAmount = 0;
	}
	virtual ~CFetchMoneyFromStorePoolResp(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRealAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRealAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d, nRealAmount=%d\n", nResult, nRealAmount);
		offset = (uint32_t)strlen(buf);
	}
};


/* 用户注册时完成必要资料填写后通知 */
#define MSGID_WEBOT_REG_AND_FILLIN_DATA_NOTIFY   0x0013FF15
class CRegAndFillInDataNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID  nRoleID;                            //玩家Uin
	CString<MaxRoleNameLength> strRoleName;     //玩家填写的昵称
	Gender  nGender;                            //注册时填写的性别
	AccountType  nAccountType;                  //账号类型，0为游客，1为179， 2为51， 3为QQ用户

public:
	CRegAndFillInDataNotify()
	{
		nRoleID = enmInvalidRoleID;
		strRoleName.Initialize();
		nGender = 0;
		nAccountType = 0;
	}
	virtual ~CRegAndFillInDataNotify(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGender);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAccountType);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGender);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAccountType);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, strRoleName=%s, nGender=%d, nAccountType=%d}\n", 
			nRoleID, strRoleName.GetString(), nGender, nAccountType);
		offset = (uint32_t)strlen(buf);
	}
};

//更新RoomServer富豪等级
#define MSGID_ISRS_UPDATEMAGNATELEVEL_NOTI	0x0013FF16
class CUpdateMagnateLevelNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateMagnateLevelNotify()
	{
		nRoleID = enmInvalidRoleID;
		nPreMagnateLevel = enmMagnateLevel_0;
		nNowMagnateLevel = enmMagnateLevel_0;
	}
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nPreMagnateLevel);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nNowMagnateLevel);
		if(0 > nRet)
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
		nRet = CCodeEngine::Decode(buf, size, offset, nPreMagnateLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nNowMagnateLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nPreMagnateLevel=%d, nNowMagnateLevel=%d\n}",
				nRoleID, nPreMagnateLevel, nNowMagnateLevel);
	    offset = (uint32_t)strlen(buf);
	}

	RoleID			nRoleID;
	MagnateLevel	nPreMagnateLevel;	//之前的富豪等级
	MagnateLevel	nNowMagnateLevel;	//升级后的富豪等级
};

#define MSGID_ISDB_GET_MAGNATE_REQ    0x0011FF17
class CGetMagnateReq : public IMsgBody
{
public:
	CGetMagnateReq()
	{
		nRoleID = enmInvalidRoleID;
	}
	virtual ~CGetMagnateReq()
	{
	}
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > nRet)
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
		sprintf(buf + offset, "{nRoleID=%d\n}", nRoleID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	RoleID 			nRoleID;
};
#define MSGID_DBIS_GET_MAGNATE_RESP    0x0012FF17
class CGetMagnateResp : public IMsgBody
{
public:
	CGetMagnateResp()
	{
		nResult = 0;
		nRoleID = enmInvalidRoleID;
		nMagnateLevel = enmMagnateLevel_0;
		nSpendMoneySum = 0;
		nNextLevelSpend = 0;
	}
	virtual ~CGetMagnateResp()
	{
	}
	int32_t	MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSpendMoneySum);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nNextLevelSpend);
		if(0 > nRet)
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
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMagnateLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSpendMoneySum);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nNextLevelSpend);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "{nResult=%d\n}", nResult);
		    offset = (uint32_t)strlen(buf);
		    return;
		}
		sprintf(buf + offset, "{nRoleID=%d, nMagnateLevel=%d, nSpendMoneySum=%lu, nNextLevelSpend=%lu\n}",
				nRoleID, nMagnateLevel, nSpendMoneySum, nNextLevelSpend);
	    offset = (uint32_t)strlen(buf);
	}
public:
	int32_t			nResult;
	RoleID 			nRoleID;
	MagnateLevel	nMagnateLevel; //富豪等级
	uint64_t		nSpendMoneySum;	//消费总额
	uint64_t		nNextLevelSpend;  //下一个等级的消费额
};
MESSAGEMAP_DECL_BEGIN(public_message)

MESSAGEMAP_DECL_MSG(MSGID_SSRS_UPDATELEVEL_NOTI, (new CUpdateVipLevelNotify()))
MESSAGEMAP_DECL_MSG(MSGID_OTDB_UPDATEASSET_REQ, (new CUpdateAssetReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBOT_UPDATEASSET_RESP, (new CUpdateAssetResp()))
MESSAGEMAP_DECL_MSG(MSGID_OTIS_UPDATEUSERASSET_REQ, (new CUpdateUserAssetReq()))
MESSAGEMAP_DECL_MSG(MSGID_ISOT_UPDATEUSERASSET_RESP, (new CUpdateUserAssetResp()))
MESSAGEMAP_DECL_MSG(MSGID_WEBAGENTTO_UPDATEASSET_NOTI, (new CPubWebUpdateAssetNoti()))

MESSAGEMAP_DECL_MSG(MSGID_DBHS_LOCKPLAYER_NOTIFY, (new CLockPlayerNotify()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_MODIFY_ROOMTTYPE_NOTIFY, (new CModifyRoomTypeNotify()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_LOCKROOM_NOTIFY, (new CLockRoomNoitfy()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_MODIFY_ROOMCAPACITY_NOTIFY, (new CModifyRoomCapacityNotify()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_BATCH_MODIFY_ROLERANK_NOTIFY, (new CBatchModifyRoomRoleRankNotify()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_LAUNCHROOM_NOTICE, (new CLauchRoomNotice()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_AUDIT_ROOMNAME_NOTIFY, (new CAuditRoomNameNotify()))
MESSAGEMAP_DECL_MSG(MSGID_SYRS_GIFT_STAR_NOTIFY,new CGiftStarNotify());

//added in 2012-05-23  11:09
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_PWDPRO_STATUSCHANGE_NOTIFY,new CPwdProStatusChangeNoti());
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_STOREPOOL_RATIOCHANGE_NOTIFY,new CStorePoolRatioChangeNotify());
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_SUPPLYSPEED_CHANGE_NOTIFY,new CSupplySpeedChangeNotify());
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_FETCHMONEY_FROM_STOREPOOL_REQ,new CFetchMoneyFromStorePoolReq());
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_SETRATIO_JACKPOT_NOTIFY, new CSetJackpotRatioNotify());

//发给RoomServer和Client的富豪等级更新协议
MESSAGEMAP_DECL_MSG(MSGID_ISRS_UPDATEMAGNATELEVEL_NOTI, new CUpdateMagnateLevelNotify());

//added in 2012-05-24 10:41
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_REG_AND_FILLIN_DATA_NOTIFY,new CRegAndFillInDataNotify());

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* PUBLIC_MESSAGE_DEFINE_H_ */
