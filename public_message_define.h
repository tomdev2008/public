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
	enmMaxSerialNumberLength		= 40,	//��ˮ����󳤶�
	enmMaxTimeStringLength			= 128,	//���ʱ�������ַ���
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
	MagnateLevel	nMagnateLevel;	//�����ȼ�
	uint64_t		nSpendMoneySum;	//�����ܶ�
	uint64_t		nNextLevelSpend;//��һ���ȼ������Ѷ�
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
* Э����������̨�����û��ʲ�֪ͨ
*/
#define MSGID_WEBAGENTTO_UPDATEASSET_NOTI  			0x0013ff02
class CPubWebUpdateAssetNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID nRoleID;                          //179uin
	AssetUpdateMode  nUpdateMode;            //����ģʽ�����ӻ��߼���, 1���ӣ�2����
	int32_t nMoneyAmount;                    //��������
	AssetUpdateChannel nUpdateChannel;       //����������0��Ч�� 1����ֵ�� 2����Ӫ��Ա����Ҽ�Ǯ
	CString<enmMaxTimeStringLength>    strDateTime;  //datetime���ͣ���2012-08-03 12:00:00	
	int32_t nSongRequest;     //���С�ߵ�����
	int32_t nRedFlower;        //С�컨������
	CString<MaxAssetUpdateReasonLength>  strReason;  //�ʲ�����ԭ��

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
			return S_OK;//��ʱPHPû�м�������ֶ�
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

// ���¿ͻ������Vip�ȼ�
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
	VipLevel	nVipLevel;		//�µ�VIP�ȼ�
	VipLevel	nPreVipLevel;	//ǰ��VIP�ȼ�
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

//web���ͷ����֪ͨ��hallserver
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

//�޸ķ������ͣ�Ŀǰ�������Ͱ���3�֣����裬���裬�İ�
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

//�����֪ͣͨ
#define MSGID_WEBOT_LOCKROOM_NOTIFY     0x0013FF0B
class CLockRoomNoitfy : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;
	RoleID  nRoomHostRoleID;   //����������roleid
	uint64_t nTimeLock;        //����Ŀ�ʼʱ��
	uint64_t nTimeUnlock;      //����Ľ���ʱ��
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

//�޸ķ��������
#define MSGID_WEBOT_MODIFY_ROOMCAPACITY_NOTIFY    0x0013FF0C
class CModifyRoomCapacityNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID   nRoomID;                //�����
	int32_t  nRoomHostRoleID;        //����������RoleID
	int32_t  nRoomShowCapacity;      //������ʾ����
	int32_t  nRoomRealCapacity;      //����ʵ������
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

//�����޸ķ������Ա��Ȩ��
#define   MSGID_WEBOT_BATCH_MODIFY_ROLERANK_NOTIFY      0x0013FF0D
class CBatchModifyRoomRoleRankNotify : public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID nRoomID;
//	RoleID  nRoomHostRoleID;
	int32_t nUserCount;       //�����˶��ٸ��˵Ĺ���ԱȨ��
	RoleID  arrRoleID[MaxAdminCountPerRoom];  //��Щ����Ա��179uin
	RoleRank  arrPreRoleRank[MaxAdminCountPerRoom]; //����֮ǰ�Ĺ���ԱȨ��
	RoleRank  arrNowRoleRank[MaxAdminCountPerRoom];  //���º�Ĺ���ԱȨ��(Ҳ�������ڵĹ���ԱȨ��)�� �����ɾ������Ȩ������ΪenmRoleRank_None
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

//��ͨ����֪ͨ
#define MSGID_WEBOT_LAUNCHROOM_NOTICE      0x0013FF0E
class CLauchRoomNotice: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID nRoomID;      //��ͨ�ķ���ķ����
	RoleID nRoleID;      //������roleid
	CString<MaxLaunchRoomNoticeLength> strLaunchRoomNotice;  //��ͨ������ʾ����
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

//���������ͨ��֪ͨ����Ӫ��̨�޸ķ������ɹ���
#define MSGID_WEBOT_AUDIT_ROOMNAME_NOTIFY        0x0013FF0F
class CAuditRoomNameNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;                           //�����
	CString<MaxRoomNameLength>  strRoomName;   //�޸ĺ�ķ�����
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

//֪ͨ��������֮��
#define MSGID_SYRS_GIFT_STAR_NOTIFY        0x00030409
class CGiftStarNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	uint16_t						nGiftStarCount;
	RoleID  						arrGiftRoleID[MaxGiftStarCount];   //�û�roleid
	ItemID	  						arrGiftItemID[MaxGiftStarCount];   //����id
	uint32_t 						arrGiftCount[MaxGiftStarCount];    //�����������

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

/*�û��ܱ�״̬�ı�֪ͨ*/
#define MSGID_WEBOT_PWDPRO_STATUSCHANGE_NOTIFY   0x0013FF11
class CPwdProStatusChangeNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID       nRoleID;   //�û�179uin
	PwdProStatus nCurPwdProStatus;   //�ı����ܱ�״̬

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

/*���봢���صı��ʷ����ı�֪ͨ*/
#define MSGID_WEBOT_STOREPOOL_RATIOCHANGE_NOTIFY   0x0013FF12
class CStorePoolRatioChangeNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	ItemID  nItemID;     //��Ʒ��ID�� uint16
	int32_t nStartTime;  //���ʵ�����ʼ��ʱ��
	int32_t nEndTime;    //���ʵ���������ʱ��
	int32_t nPreRatio;   //����֮ǰ�Ĵ������ʣ� ��20%��Ǯ���봢���أ����ֵΪ20
	int32_t nNowRatio;   //����֮��Ĵ������ʣ���40%�� ���ֵΪ40

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

/*���ز����ٶȸı�֪ͨ*/
#define MSGID_WEBOT_SUPPLYSPEED_CHANGE_NOTIFY     0x0013FF13
class  CSupplySpeedChangeNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	ItemID  nItemID;  //��ƷID
	int32_t nAmount;       //��������������λ���ң�
	int32_t nMultiple;     //���뽱�صı�������10�� 50�� 500�ȵ�

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

/* ��Ӫ��Ա�Ӵ�������Ǯ֪ͨ */
#define MSGID_WEBOT_FETCHMONEY_FROM_STOREPOOL_REQ   0x0011FF14
class CFetchMoneyFromStorePoolReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID  nRoleID;    //��ҵ�179uin
	int32_t nAmount;    //������Ǯ������

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

/* ��Ӫ��Ա�޸��н�����֪ͨ */
#define MSGID_WEBOT_SETRATIO_JACKPOT_NOTIFY   0x0011FF15
class CSetJackpotRatioNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t	nItemID;    //����ID
	int32_t nCount;   //���ظ���
	int32_t	nMultipe[MaxJackpotCountPerLuckyItem];   //���ر���
	int32_t	nRatio[MaxJackpotCountPerLuckyItem];    //����˱������ص�Ǯ�ұ���
	int32_t nProbability[MaxJackpotCountPerLuckyItem];//�д˱����ĸ���
	int8_t	nFlag[MaxJackpotCountPerLuckyItem];		//0��ʾ�ý���ģʽ��1��ʾ�ø���ģʽ

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

/* ��Ӫ��Ա�Ӵ�������Ǯ��Ӧ */
#define MSGID_BSWEB_FETCHMONEY_FROM_STOREPOOL_RESP    0x0012FF14
class CFetchMoneyFromStorePoolResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;      //����ֵ��0Ϊ������С��0��ʾ���������ݿ����ʧ�ܵȣ�
	int32_t nRealAmount;  //ʵ����Ǯ�����������п��������е��������ڴ������е�ʣ��������
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


/* �û�ע��ʱ��ɱ�Ҫ������д��֪ͨ */
#define MSGID_WEBOT_REG_AND_FILLIN_DATA_NOTIFY   0x0013FF15
class CRegAndFillInDataNotify: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID  nRoleID;                            //���Uin
	CString<MaxRoleNameLength> strRoleName;     //�����д���ǳ�
	Gender  nGender;                            //ע��ʱ��д���Ա�
	AccountType  nAccountType;                  //�˺����ͣ�0Ϊ�οͣ�1Ϊ179�� 2Ϊ51�� 3ΪQQ�û�

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

//����RoomServer�����ȼ�
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
	MagnateLevel	nPreMagnateLevel;	//֮ǰ�ĸ����ȼ�
	MagnateLevel	nNowMagnateLevel;	//������ĸ����ȼ�
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
	MagnateLevel	nMagnateLevel; //�����ȼ�
	uint64_t		nSpendMoneySum;	//�����ܶ�
	uint64_t		nNextLevelSpend;  //��һ���ȼ������Ѷ�
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

//����RoomServer��Client�ĸ����ȼ�����Э��
MESSAGEMAP_DECL_MSG(MSGID_ISRS_UPDATEMAGNATELEVEL_NOTI, new CUpdateMagnateLevelNotify());

//added in 2012-05-24 10:41
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_REG_AND_FILLIN_DATA_NOTIFY,new CRegAndFillInDataNotify());

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END

#endif /* PUBLIC_MESSAGE_DEFINE_H_ */
