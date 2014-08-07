/*
 * itemserver_message_define.h
 *
 *  Created on: 2012-2-9
 *      Author: jimm
 */

#ifndef ITEMSERVER_MESSAGE_DEFINE_H_
#define ITEMSERVER_MESSAGE_DEFINE_H_

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_msg_impl.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include <stdio.h>
#include "hallserver_message_define.h"

FRAME_NAMESPACE_BEGIN

#define MSGID_ISDB_BATCHUPDATEASSET_REQ					0x00110801
class CBatchUpdateAssetReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBatchUpdateAssetReq()
	{
		strTransID.Initialize();
		nUpdateCount = 0;
		memset(arrCauseID, 0, sizeof(arrCauseID));
		memset(arrRoleID, 0, sizeof(arrRoleID));
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}

	virtual ~CBatchUpdateAssetReq()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
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
		nRet = CCodeEngine::Decode(buf, size, offset, nUpdateCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
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
		sprintf(buf + offset, "{strTransID=%s, nUpdateCount=%d, arrCauseID={",
				strTransID.GetString(), nUpdateCount);
	    offset = (uint32_t)strlen(buf);
	    if(nUpdateCount > 0)
	    {
	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrCauseID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrRoleID={", arrCauseID[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrRoleID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrAssetType={", arrRoleID[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
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
	    	sprintf(buf + offset, "}, arrRoleID={}, arrAssetType={}, arrAssetValue={}}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	int32_t					nUpdateCount;
	CauseID					arrCauseID[MaxBatchUpdateRoleAssetCount];
	RoleID					arrRoleID[MaxBatchUpdateRoleAssetCount];
	AssetType				arrAssetType[MaxBatchUpdateRoleAssetCount];
	UpdateAssetOperate		arrUpdateAssetOperate[MaxBatchUpdateRoleAssetCount];
	uint32_t				arrAssetValue[MaxBatchUpdateRoleAssetCount];
};


#define MSGID_DBIS_BATCHUPDATEASSET_RESP				0x00120801
class CBatchUpdateAssetResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBatchUpdateAssetResp()
	{
		nResult = 0;
		strTransID.Initialize();
		nUpdateCount = 0;
		memset(arrCauseID, 0, sizeof(arrCauseID));
		memset(arrRoleID, 0, sizeof(arrRoleID));
		memset(arrAssetType, 0, sizeof(arrAssetType));
		memset(arrUpdateAssetOperate, 0, sizeof(arrUpdateAssetOperate));
		memset(arrAssetValue, 0, sizeof(arrAssetValue));
	}

	virtual ~CBatchUpdateAssetResp()
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = strTransID.MessageEncode(buf, size, offset);
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
			nRet = CCodeEngine::Encode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = strTransID.MessageDecode(buf, size, offset);
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
			nRet = CCodeEngine::Decode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUpdateCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
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
		sprintf(buf + offset, "{nResult=0x%08x", nResult);
	    offset = (uint32_t)strlen(buf);
	    if(nResult != S_OK)
	    {
	    	sprintf(buf + offset, "}");
	    	offset = (uint32_t)strlen(buf);
	    	return;
	    }

		sprintf(buf + offset, ", strTransID=%s, nUpdateCount=%d, arrCauseID={",
				strTransID.GetString(), nUpdateCount);
	    offset = (uint32_t)strlen(buf);
	    if(nUpdateCount > 0)
	    {
	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrCauseID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrRoleID={", arrCauseID[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrRoleID[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrAssetType={", arrRoleID[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrAssetType[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrUpdateAssetOperate={", arrAssetType[nUpdateCount - 1]);
	    	offset = (uint32_t)strlen(buf);

	    	for(int32_t i = 0; i < nUpdateCount - 1; ++i)
	    	{
	    		sprintf(buf + offset, "%d, ", arrUpdateAssetOperate[i]);
	    		offset = (uint32_t)strlen(buf);
	    	}
	    	sprintf(buf + offset, "%d}, arrAssetValue={", arrUpdateAssetOperate[nUpdateCount - 1]);
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
	    	sprintf(buf + offset, "}, arrRoleID={}, arrAssetType={}, arrUpdateAssetOperate={}, arrAssetValue={}}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}

public:
	int32_t					nResult;
	CString<enmMaxSerialNumberLength>	strTransID;
	int32_t					nUpdateCount;
	CauseID					arrCauseID[MaxBatchUpdateRoleAssetCount];
	RoleID					arrRoleID[MaxBatchUpdateRoleAssetCount];
	AssetType				arrAssetType[MaxBatchUpdateRoleAssetCount];
	UpdateAssetOperate		arrUpdateAssetOperate[MaxBatchUpdateRoleAssetCount];
	uint32_t				arrAssetValue[MaxBatchUpdateRoleAssetCount];
};


#define MSGID_ISDB_UPDATEITEM_REQ					0x00110802
class CUpdateItemReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateItemReq()
	{
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nItemCount = 0;
		memset(arrCauseID, 0, sizeof(arrCauseID));
		memset(arrUpdateOperate, 0, sizeof(arrUpdateOperate));
		memset(arrItemUnit, 0, sizeof(arrItemUnit));
	}

	virtual ~CUpdateItemReq()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nOwnTick);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nOwnTick);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strTransID=%s, nRoleID=%d, nItemCount=%d, arrItemUnit={",
				strTransID.GetString(), nRoleID, nItemCount);
	    offset = (uint32_t)strlen(buf);
	    if(nItemCount > 0)
	    {
	    	for(int32_t i = 0; i < nItemCount - 1; ++i)
			{
				sprintf(buf + offset, "{arrCauseID[%d]=%d, UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}, ",
						i,arrCauseID[i],arrUpdateOperate[i],arrItemUnit[i].nItemID, arrItemUnit[i].nUseMeans,
						arrItemUnit[i].nQuantity, arrItemUnit[i].nOwnTick);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "{arrCauseID[%d]=%d, UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}}",
					nItemCount - 1,arrCauseID[nItemCount - 1],arrUpdateOperate[nItemCount - 1],arrItemUnit[nItemCount - 1].nItemID, arrItemUnit[nItemCount - 1].nUseMeans,
					arrItemUnit[nItemCount - 1].nQuantity, arrItemUnit[nItemCount - 1].nOwnTick);
			offset = (uint32_t)strlen(buf);
	    }
	    else
	    {
			sprintf(buf + offset, "}}");
			offset = (uint32_t)strlen(buf);
	    }
	}
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID					nRoleID;
	int32_t					nItemCount;
	CauseID					arrCauseID[MaxOnUserItemCount];
	UpdateItemOperate		arrUpdateOperate[MaxOnUserItemCount];
	ItemUnit				arrItemUnit[MaxOnUserItemCount];
};

#define MSGID_DBIS_UPDATEITEM_RESP					0x00120802
class CUpdateItemResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateItemResp()
	{
		nResult = 0;
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nItemCount = 0;
		memset(arrUpdateOperate, 0, sizeof(arrUpdateOperate));
		memset(arrItemUnit, 0, sizeof(arrItemUnit));
	}

	virtual ~CUpdateItemResp()
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
		if(nResult < 0)
		{
			return S_OK;
		}
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
		nRet = CCodeEngine::Encode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nOwnTick);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult < 0)
		{
			return S_OK;
		}
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
		nRet = CCodeEngine::Decode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nOwnTick);
			if(nRet < 0)
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
			sprintf(buf + offset, ", strTransID=%s, nRoleID=%d, nItemCount=%d, arrItemUnit={",
					strTransID.GetString(), nRoleID, nItemCount);
			offset = (uint32_t)strlen(buf);
			if(nItemCount > 0)
			{
				for(int32_t i = 0; i < nItemCount - 1; ++i)
				{
					sprintf(buf + offset, "{UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}, ",
							arrUpdateOperate[i],arrItemUnit[i].nItemID, arrItemUnit[i].nUseMeans,
							arrItemUnit[i].nQuantity, arrItemUnit[i].nOwnTick);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "{UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}}",
						arrUpdateOperate[nItemCount - 1],arrItemUnit[nItemCount - 1].nItemID, arrItemUnit[nItemCount - 1].nUseMeans,
						arrItemUnit[nItemCount - 1].nQuantity, arrItemUnit[nItemCount - 1].nOwnTick);
				offset = (uint32_t)strlen(buf);
			}
			else
			{
				sprintf(buf + offset, "}}");
				offset = (uint32_t)strlen(buf);
			}
		}
	}
public:
	int32_t					nResult;
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID					nRoleID;
	int32_t					nItemCount;
	UpdateItemOperate		arrUpdateOperate[MaxOnUserItemCount];
	ItemUnit				arrItemUnit[MaxOnUserItemCount];
};

#define MSGID_ISDB_GETROLEITEMINFO_REQ					0x00110803
class CGetRoleItemInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetRoleItemInfoReq()
	{
		nUserCount = 0;
		for(int32_t i = 0; i < MaxUserCountPerRoom; ++i)
		{
			arrRoleID[i] = enmInvalidRoleID;
		}
	}

	virtual ~CGetRoleItemInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nUserCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nUserCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nUserCount=%d, arrRoleID={", nUserCount);
	    offset = (uint32_t)strlen(buf);
	    if(nUserCount > 0)
	    {
			for(int32_t i = 0; i < nUserCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrRoleID[i]);
				offset = (uint32_t)strlen(buf);
			}
	    	sprintf(buf + offset, "%d}}", arrRoleID[nUserCount - 1]);
	    	offset = (uint32_t)strlen(buf);
	    }
	    else
	    {
	    	sprintf(buf + offset, "}}");
	    	offset = (uint32_t)strlen(buf);
	    }
	}

public:
	int32_t				nUserCount;
	RoleID				arrRoleID[MaxUserCountPerRoom];

};

#define MSGID_DBIS_GETROLEITEMINFO_RESP					0x00120803
class CGetRoleItemInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetRoleItemInfoResp()
	{
		nResult = 0;
		nUserCount = 0;
		for(int32_t i = 0; i < MaxUserCountPerRoom; ++i)
		{
			arrRoleID[i] = enmInvalidRoleID;
		}
		memset(arrItemCount, 0, sizeof(arrItemCount));
		memset(arrItemUnit, 0, sizeof(arrItemUnit));
	}

	virtual ~CGetRoleItemInfoResp()
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nUserCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			for(int32_t j = 0; j < arrItemCount[i]; ++j)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i][j].nItemID);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i][j].nUseMeans);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i][j].nQuantity);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i][j].nOwnTick);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nUserCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nUserCount; ++i)
		{
			for(int32_t j = 0; j < arrItemCount[i]; ++j)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i][j].nItemID);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i][j].nUseMeans);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i][j].nQuantity);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i][j].nOwnTick);
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
		sprintf(buf + offset, "{nResult=%d, nUserCount=%d, ", nResult, nUserCount);
	    offset = (uint32_t)strlen(buf);
	    for(int32_t i = 0; i < nUserCount; ++i)
	    {
	    	sprintf(buf + offset, "{nRoleID=%d, nItemCount=%d, arrItemUnit={", arrRoleID[i], arrItemCount[i]);
	    	offset = (uint32_t)strlen(buf);
	    	if(arrItemCount[i] > 0)
	    	{
				for(int32_t j = 0; j < arrItemCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "{nItemID=%d, nUseMeans=%d, nQuantity=%d, nOwnTick=%d},",
							arrItemUnit[i][j].nItemID, arrItemUnit[i][j].nUseMeans, arrItemUnit[i][j].nQuantity, arrItemUnit[i][j].nOwnTick);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "{nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}}}",
						arrItemUnit[i][arrItemCount[i] - 1].nItemID, arrItemUnit[i][arrItemCount[i] - 1].nUseMeans,
						arrItemUnit[i][arrItemCount[i] - 1].nQuantity, arrItemUnit[i][arrItemCount[i] - 1].nOwnTick);
			    offset = (uint32_t)strlen(buf);
	    	}
	    	else
	    	{
	    		sprintf(buf + offset, "{}}");
	    		offset = (uint32_t)strlen(buf);
	    	}
	    }
	}

public:
	int32_t				nResult;
	int32_t				nUserCount;
	RoleID				arrRoleID[MaxUserCountPerRoom];
	int32_t				arrItemCount[MaxUserCountPerRoom];
	ItemUnit			arrItemUnit[MaxUserCountPerRoom][MaxOnUserItemCount];

};

#define MSGID_ISDB_GETITEMJACKPOTINFO_REQ					0x00110804
class CGetItemJackpotInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetItemJackpotInfoReq()
	{
		nStartIndex = 0;
		nWantCount = 0;
	}

	virtual ~CGetItemJackpotInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nStartIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}
		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nStartIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}
		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nStartIndex=%d, nWantCount=%d}", nStartIndex, nWantCount);
	    offset = (uint32_t)strlen(buf);
	}

public:
	int32_t				nStartIndex;
	int32_t				nWantCount;

};

#define MSGID_DBIS_GETITEMJACKPOTINFO_RESP					0x00120804
class CGetItemJackpotInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetItemJackpotInfoResp()
	{
		nResult = 0;
		nItemCount = 0;
		for(int32_t i = 0; i < MaxGetJackpotInfoCount; ++i)
		{
			arrItemID[i] = enmInvalidItemID;
		}
		memset(arrItemMultipeCount, 0, sizeof(arrItemMultipeCount));
		memset(arrItemMultipe, 0, sizeof(arrItemMultipe));
		memset(arrItemRatio, 0, sizeof(arrItemRatio));
		memset(arrItemRatioJackpot, 0, sizeof(arrItemRatioJackpot));
		memset(arrItemProbability, 0, sizeof(arrItemProbability));
		memset(arrItemProbabilityJackpot, 0, sizeof(arrItemProbabilityJackpot));
		memset(arrItemFlag, 0, sizeof(arrItemFlag));
	}

	virtual ~CGetItemJackpotInfoResp()
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemMultipeCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			for(int32_t j = 0; j < arrItemMultipeCount[i]; ++j)
			{
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemMultipe[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemRatio[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemRatioJackpot[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemProbability[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemProbabilityJackpot[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(buf, size, offset, arrItemFlag[i][j]);
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemMultipeCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			for(int32_t j = 0; j < arrItemMultipeCount[i]; ++j)
			{
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemMultipe[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemRatio[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemRatioJackpot[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemProbability[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemProbabilityJackpot[i][j]);
				if(nRet < 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Decode(buf, size, offset, arrItemFlag[i][j]);
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
		sprintf(buf + offset, "{nResult=%d, nItemCount=%d, ", nResult, nItemCount);
	    offset = (uint32_t)strlen(buf);
	    for(int32_t i = 0; i < nItemCount; ++i)
	    {
	    	sprintf(buf + offset, "{nItemID=0x%04x, arrItemMultipeCount=%d, arrItemMultipe={",
	    			arrItemID[i], arrItemMultipeCount[i]);
	    	offset = (uint32_t)strlen(buf);
	    	if(arrItemMultipeCount[i] > 0)
	    	{
				for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemMultipe[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}, arrItemRatio={", arrItemMultipe[i][arrItemMultipeCount[i] - 1]);
			    offset = (uint32_t)strlen(buf);
				for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemRatio[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}, arrItemRatioJackpot={", arrItemRatio[i][arrItemMultipeCount[i] - 1]);
			    offset = (uint32_t)strlen(buf);
			    for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemRatioJackpot[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}, arrItemProbability={", arrItemRatioJackpot[i][arrItemMultipeCount[i] - 1]);
				offset = (uint32_t)strlen(buf);
				for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemProbability[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}, arrItemProbabilityJackpot={", arrItemProbability[i][arrItemMultipeCount[i] - 1]);
				offset = (uint32_t)strlen(buf);
				for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemProbabilityJackpot[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}, arrItemFlag={", arrItemProbabilityJackpot[i][arrItemMultipeCount[i] - 1]);
				offset = (uint32_t)strlen(buf);
				for(int32_t j = 0; j < arrItemMultipeCount[i] - 1; ++j)
				{
					sprintf(buf + offset, "%d, ", arrItemFlag[i][j]);
					offset = (uint32_t)strlen(buf);
				}
				sprintf(buf + offset, "%d}}", arrItemFlag[i][arrItemMultipeCount[i] - 1]);
				offset = (uint32_t)strlen(buf);
	    	}
	    	else
	    	{
	    		sprintf(buf + offset, "}, arrItemJackpot={}}");
	    		offset = (uint32_t)strlen(buf);
	    	}
	    }
	}

public:
	int32_t				nResult;
	int32_t				nItemCount;
	ItemID				arrItemID[MaxGetJackpotInfoCount];
	uint8_t				arrItemMultipeCount[MaxGetJackpotInfoCount];
	uint16_t			arrItemMultipe[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
	int32_t				arrItemRatio[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
	int32_t				arrItemRatioJackpot[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
	int32_t				arrItemProbability[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
	int32_t				arrItemProbabilityJackpot[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
	int8_t				arrItemFlag[MaxGetJackpotInfoCount][MaxJackpotCountPerLuckyItem];
};

#define MSGID_ISDB_SETITEMJACKPOTINFO_REQ					0x00110805
class CSetItemJackpotInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetItemJackpotInfoReq()
	{
		nItemID = enmInvalidItemID;
		nItemMultipeCount = 0;
		memset(arrItemMultipe, 0, sizeof(arrItemMultipe));
		memset(arrItemRatio, 0, sizeof(arrItemRatio));
		memset(arrItemRatioJackpot, 0, sizeof(arrItemRatioJackpot));
		memset(arrItemProbability, 0, sizeof(arrItemProbability));
		memset(arrItemProbabilityJackpot, 0, sizeof(arrItemProbabilityJackpot));
		memset(arrItemFlag, 0, sizeof(arrItemFlag));
	}

	virtual ~CSetItemJackpotInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nItemMultipeCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemMultipeCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemRatio[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemRatioJackpot[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemProbability[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemProbabilityJackpot[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemFlag[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nItemMultipeCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemMultipeCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemRatio[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemRatioJackpot[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemProbability[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemProbabilityJackpot[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemFlag[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nItemID=0x%04x, nItemMultipeCount=%d, arrItemMultipe={",
				nItemID, nItemMultipeCount);
		offset = (uint32_t)strlen(buf);
		if(nItemMultipeCount > 0)
		{
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemMultipe[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrItemRatio={", arrItemMultipe[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemRatio[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrItemRatioJackpot={", arrItemRatio[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemRatioJackpot[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrItemProbability={", arrItemRatioJackpot[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemProbability[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrItemProbabilityJackpot={", arrItemProbability[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemProbabilityJackpot[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}, arrItemFlag={", arrItemProbabilityJackpot[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
			for(int32_t i = 0; i < nItemMultipeCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrItemFlag[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}}", arrItemFlag[nItemMultipeCount - 1]);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "}, arrItemJackpot={}}");
			offset = (uint32_t)strlen(buf);
		}
	}

public:
	ItemID				nItemID;
	int32_t				nItemMultipeCount;
	int32_t				arrItemMultipe[MaxJackpotCountPerLuckyItem];
	int32_t				arrItemRatio[MaxJackpotCountPerLuckyItem];
	int32_t				arrItemRatioJackpot[MaxJackpotCountPerLuckyItem];
	int32_t				arrItemProbability[MaxJackpotCountPerLuckyItem];
	int32_t				arrItemProbabilityJackpot[MaxJackpotCountPerLuckyItem];
	int8_t				arrItemFlag[MaxJackpotCountPerLuckyItem];
};


#define MSGID_ISRS_NEEDREBULID_NOTICE					0x00130806
class CNeedRebulidNotice : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CNeedRebulidNotice()
	{
	}

	virtual ~CNeedRebulidNotice()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nothing}");
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_ISHS_GETONLINEPLAYERINFOINFO_REQ					0x00110807
class CGetOnlinePlayerInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetOnlinePlayerInfoReq()
	{
		nSeq = 0;
		nWantCount = 0;
	}

	virtual ~CGetOnlinePlayerInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nSeq);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nSeq);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nSeq=%u, nWantCount=%d}", nSeq, nWantCount);
		offset = (uint32_t)strlen(buf);
	}

public:
	uint32_t			nSeq;
	int32_t				nWantCount;
};

#define MSGID_HSIS_GETONLINEPLAYERINFOINFO_RESP					0x00120807
class CGetOnlinePlayerInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetOnlinePlayerInfoResp()
	{
		nResult = 0;
		nSeq = 0;
		nPlayerCount = 0;
	}

	virtual ~CGetOnlinePlayerInfoResp()
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

		if(nResult < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nSeq);
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
			nRet = arrOnlinePlayer[i].MessageEncode(buf, size, offset);
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

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}

		if(nResult < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nSeq);
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
			nRet = arrOnlinePlayer[i].MessageDecode(buf, size, offset);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		if(nResult < 0)
		{
			sprintf(buf + offset, "{nResult=%d", nResult);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, ", nSeq=%u, nPlayerCount=%d, {", nSeq, nPlayerCount);
			offset = (uint32_t)strlen(buf);

			for(int32_t i = 0; i < nPlayerCount; ++i)
			{
				arrOnlinePlayer[i].Dump(buf, size, offset);
			}

			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
		}

		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}

public:
	int32_t				nResult;
	uint32_t			nSeq;
	int32_t				nPlayerCount;
	COnlineNoti			arrOnlinePlayer[MaxGetOnlinePlayerCount];
};

#define MSGID_ISDB_SETSTOREPOOLINFO_REQ							0x00110808
class CSetStorePoolInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetStorePoolInfoReq()
	{
		nStorePool = 0;
	}

	virtual ~CSetStorePoolInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nStorePool);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nStorePool);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nStorePool=%d}", nStorePool);
		offset = (uint32_t)strlen(buf);
	}

public:
	int32_t				nStorePool;
};

#define MSGID_DBIS_SETSTOREPOOLINFO_RESP							0x00120808
class CSetStorePoolInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetStorePoolInfoResp()
	{
		nResult = 0;
	}

	virtual ~CSetStorePoolInfoResp()
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

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}", nResult);
		offset = (uint32_t)strlen(buf);
	}

public:
	int32_t				nResult;
};

#define MSGID_ISDB_GETSTOREPOOLINFO_REQ							0x00110809
class CGetStorePoolInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetStorePoolInfoReq()
	{
		nItemID = enmInvalidItemID;
	}

	virtual ~CGetStorePoolInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nItemID=0x%04x}", nItemID);
		offset = (uint32_t)strlen(buf);
	}

public:
	ItemID					nItemID;
};

#define MSGID_DBIS_GETSTOREPOOLINFO_RESP							0x00120809
class CGetStorePoolInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetStorePoolInfoResp()
	{
		nResult = 0;
		nStorePool = 0;
	}

	virtual ~CGetStorePoolInfoResp()
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

		if(nResult != S_OK)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nStorePool);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;

		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}

		if(nResult != S_OK)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nStorePool);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d", nResult);
		offset = (uint32_t)strlen(buf);
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "}");
		}
		else
		{
			sprintf(buf + offset, ", nStorePool=%d}", nStorePool);
		}
		offset = (uint32_t)strlen(buf);
	}

public:
	int32_t					nResult;
	int32_t					nStorePool;
};

//大笔消费通知
#define MSGID_ISRS_BIGCONSUME_NOTI							0x0013080a
class CBigConsumeNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CBigConsumeNoti()
	{
		nRoomID = enmInvalidRoomID;
		nSrcRoleID = enmInvalidRoleID;
		nDstRoleID = enmInvalidRoleID;
		nItemID = enmInvalidItemID;
		strItemName.Initialize();
		nItemCount = 0;
		nConsumeMoney = 0;
	}

	virtual ~CBigConsumeNoti()
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

		nRet = CCodeEngine::Encode(buf, size, offset, nSrcRoleID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nDstRoleID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = strItemName.MessageEncode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(buf, size, offset, nConsumeMoney);
		if(nRet < 0)
		{
			return nRet;
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

		nRet = CCodeEngine::Decode(buf, size, offset, nSrcRoleID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nDstRoleID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = strItemName.MessageDecode(buf, size, offset);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nConsumeMoney);
		if(nRet < 0)
		{
			return nRet;
		}

		return nRet;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nSrcRoleID=%d, nDstRoleID=%d, nItemID=0x%04x, strItemName=%s, nItemCount=%d, nConsumeMoney=%d}",
				nRoomID, nSrcRoleID, nDstRoleID, nItemID, strItemName.GetString(), nItemCount, nConsumeMoney);
		offset = (uint32_t)strlen(buf);
	}

public:
	RoomID					nRoomID;
	RoleID					nSrcRoleID;
	RoleID					nDstRoleID;
	ItemID					nItemID;
	CString<MaxItemNameSize>strItemName;
	int32_t					nItemCount;
	int32_t					nConsumeMoney;
};


#define MSGID_ISDB_GETROLEPACKSACKINFO_REQ					0x0011080b
class CGetRolePackSackInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetRolePackSackInfoReq()
	{
		nRoleID = enmInvalidRoleID;
	}

	virtual ~CGetRolePackSackInfoReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d}", nRoleID);
	    offset = (uint32_t)strlen(buf);
	}

public:
	RoleID				nRoleID;
};

#define MSGID_DBIS_GETROLEPACKSACKINFO_RESP					0x0012080b
class CGetRolePackSackInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetRolePackSackInfoResp()
	{
		nResult = 0;
		nGoodCount = 0;
		memset(arrGoodInfo, 0, sizeof(arrGoodInfo));
	}

	virtual ~CGetRolePackSackInfoResp()
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGoodCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nGoodCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrGoodInfo[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrGoodInfo[i].nCount);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrGoodInfo[i].nOwnTick);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrGoodInfo[i].nKeepTime);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nGoodCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nGoodCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrGoodInfo[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrGoodInfo[i].nCount);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrGoodInfo[i].nOwnTick);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrGoodInfo[i].nKeepTime);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nGoodCount=%d, arrGoodInfo={", nResult, nGoodCount);
	    offset = (uint32_t)strlen(buf);
		if(nGoodCount > 0)
		{
			for(int32_t i = 0; i < nGoodCount - 1; ++i)
			{
				sprintf(buf + offset, "{nItemID=%d, nCount=%d, nOwnTick=%d, nKeepTime=%d}, ",
						arrGoodInfo[i].nItemID, arrGoodInfo[i].nCount, arrGoodInfo[i].nOwnTick, arrGoodInfo[i].nKeepTime);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "{nItemID=0x%04x, nCount=%d, nOwnTick=%d, nKeepTime=%d}}}",
					arrGoodInfo[nGoodCount - 1].nItemID, arrGoodInfo[nGoodCount - 1].nCount,
					arrGoodInfo[nGoodCount - 1].nOwnTick, arrGoodInfo[nGoodCount - 1].nKeepTime);
			offset = (uint32_t)strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "}}");
			offset = (uint32_t)strlen(buf);
		}
	}

public:
	int32_t				nResult;
	int32_t				nGoodCount;
	GoodInfo			arrGoodInfo[MaxOnUserItemCount];
};


#define MSGID_ISDB_UPDATEGOOD_REQ					0x0011080c
class CUpdateGoodReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateGoodReq()
	{
		strTransID.Initialize();
		nRoleID = enmInvalidRoleID;
		nItemCount = 0;
		memset(arrCauseID, 0, sizeof(arrCauseID));
		memset(arrUpdateOperate, 0, sizeof(arrUpdateOperate));
		memset(arrItemUnit, 0, sizeof(arrItemUnit));
		memset(arrExpireTime, 0, sizeof(arrExpireTime));
	}

	virtual ~CUpdateGoodReq()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemUnit[i].nOwnTick);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrExpireTime[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nItemCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrCauseID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrUpdateOperate[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nItemID);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nUseMeans);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nQuantity);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemUnit[i].nOwnTick);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		for(int32_t i = 0; i < nItemCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrExpireTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{strTransID=%s, nRoleID=%d, nItemCount=%d, arrItemUnit={",
				strTransID.GetString(), nRoleID, nItemCount);
	    offset = (uint32_t)strlen(buf);
	    if(nItemCount > 0)
	    {
	    	for(int32_t i = 0; i < nItemCount - 1; ++i)
			{
				sprintf(buf + offset, "{arrCauseID[%d]=%d, UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}, ",
						i,arrCauseID[i],arrUpdateOperate[i],arrItemUnit[i].nItemID, arrItemUnit[i].nUseMeans,
						arrItemUnit[i].nQuantity, arrItemUnit[i].nOwnTick);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "{arrCauseID[%d]=%d, UpdateOperate=%d, nItemID=0x%04x, nUseMeans=%d, nQuantity=%d, nOwnTick=%d}",
					nItemCount - 1,arrCauseID[nItemCount - 1],arrUpdateOperate[nItemCount - 1],arrItemUnit[nItemCount - 1].nItemID, arrItemUnit[nItemCount - 1].nUseMeans,
					arrItemUnit[nItemCount - 1].nQuantity, arrItemUnit[nItemCount - 1].nOwnTick);
			offset = (uint32_t)strlen(buf);

			for(int32_t i = 0; i < nItemCount - 1; ++i)
			{
				sprintf(buf + offset, "%d, ", arrExpireTime[i]);
				offset = (uint32_t)strlen(buf);
			}
			sprintf(buf + offset, "%d}}", arrExpireTime[nItemCount - 1]);
			offset = (uint32_t)strlen(buf);
	    }
		sprintf(buf + offset, "}, arrExpireTime={}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID					nRoleID;
	int32_t					nItemCount;
	CauseID					arrCauseID[MaxPlayerGoodsCount];
	UpdateItemOperate		arrUpdateOperate[MaxPlayerGoodsCount];
	ItemUnit				arrItemUnit[MaxPlayerGoodsCount];
	int32_t					arrExpireTime[MaxPlayerGoodsCount];
};

#define MSGID_DBIS_UPDATEGOOD_RESP					0x0012080c
class CUpdateGoodResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateGoodResp()
	{
		nResult = 0;
	}

	virtual ~CUpdateGoodResp()
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

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}", nResult);
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t					nResult;
};

//更新其他服务器用户身份的通知
#define MSGID_ISOS_UPDATEIDENTITY_NOTI				0x0011080d
class CUpdateIdentityNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateIdentityNoti()
	{
		nCount = 0;
		memset(nRoleID, 0, sizeof(nRoleID));
		memset(nIdentityType, 0, sizeof(nIdentityType));
	}

	virtual ~CUpdateIdentityNoti()
	{
	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nIdentityType[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nIdentityType[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nCount=%d,{", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "nRoleID=%d, nIdentityType=%d; ", nRoleID[i], nIdentityType[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int8_t			nCount;
	RoleID			nRoleID[MaxIdentityCount];
	IdentityType	nIdentityType[MaxIdentityCount];
};

////更新财富宝座通知
//#define MSGID_ISDB_SETONCEMAXSPEND_NOTICE				0x0013080e
//class CSetOnceMaxSpendNoti : public IMsgBody
//{
//public:
//	CSetOnceMaxSpendNoti()
//	{
//		nRoomID = enmInvalidRoomID;
//		nRoleID = enmInvalidRoleID;
//		nAccountID = enmInvalidAccountID;
//		nMoney = 0;
//		strRoleName = "";
//		nDate = 0;
//	}
//
//	virtual ~CSetOnceMaxSpendNoti()
//	{
//	}
//
//	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t nRet = S_OK;
//		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Encode(buf, size, offset, nAccountID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Encode(buf, size, offset, nMoney);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::MessageEncode(buf, size, offset, strRoleName);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Encode(buf, size, offset, nDate);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		return S_OK;
//	}
//
//	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t nRet = S_OK;
//		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Decode(buf, size, offset, nAccountID);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Decode(buf, size, offset, nMoney);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::MessageDecode(buf, size, offset, strRoleName);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Decode(buf, size, offset, nDate);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//
//		return S_OK;
//	}
//	void Dump(char* buf, const uint32_t size, uint32_t& offset)
//	{
//		sprintf(buf + offset, "{nRoomID=%d, nRoleID=%d, nAccountID=%d, nMoney=%d, strRoleName=%s, nDate=%d}",
//				nRoomID, nRoleID, nAccountID, nMoney, strRoleName.GetString(), nDate);
//		offset = (uint32_t)strlen(buf);
//	}
//public:
//	RoomID		nRoomID;	//房间ID
//	RoleID		nRoleID;	//RoleID
//	AccountID	nAccountID;	//179ID
//	uint32_t	nMoney;	//单笔最大消费金额
//	CString<MaxRoleNameLength>		strRoleName;	//昵称
//	int32_t		nDate;	//日期  格式如:20121230
//};
//
////取得财富宝座请求
//#define MSGID_ISDB_GETONCEMAXSPEND_REQ				0x0011080f
//class CGetOnceMaxSpendReq : public IMsgBody
//{
//public:
//	CGetOnceMaxSpendReq()
//	{
//	}
//
//	virtual ~CGetOnceMaxSpendReq()
//	{
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
//		sprintf(buf + offset, "{nothing}");
//		offset = (uint32_t)strlen(buf);
//	}
//};
//
////取得财富宝座响应
//#define MSGID_ISDB_GETONCEMAXSPEND_RESP				0x0012080f
//class CGetOnceMaxSpendResp : public IMsgBody
//{
//public:
//	CGetOnceMaxSpendResp()
//	{
//		nResult = 0;
//		nCount = 0;
//		for(int32_t i = 0; i < MaxRoomCountPerServer; ++i)
//		{
//			nRoomID[i] = enmInvalidRoomID;
//			nRoleID[i] = enmInvalidRoleID;
//			nAccountID[i] = enmInvalidAccountID;
//			nMoney[i] = 0;
//			strRoleName[i] = "";
//			nDate[i] = 0;
//		}
//	}
//
//	virtual ~CGetOnceMaxSpendResp()
//	{
//	}
//
//	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t nRet = S_OK;
//		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		for(int32_t i = 0; i < nCount; ++i)
//		{
//			nRet = CCodeEngine::Encode(buf, size, offset, nRoomID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Encode(buf, size, offset, nAccountID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Encode(buf, size, offset, nMoney[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::MessageEncode(buf, size, offset, strRoleName[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Encode(buf, size, offset, nDate[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//		}
//
//		return S_OK;
//	}
//
//	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t nRet = S_OK;
//		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		if(nResult != S_OK)
//		{
//			return S_OK;
//		}
//		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
//		if(nRet < 0)
//		{
//			return nRet;
//		}
//		for(int32_t i = 0; i < nCount; ++i)
//		{
//			nRet = CCodeEngine::Decode(buf, size, offset, nRoomID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Decode(buf, size, offset, nAccountID[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Decode(buf, size, offset, nMoney[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::MessageDecode(buf, size, offset, strRoleName[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//			nRet = CCodeEngine::Decode(buf, size, offset, nDate[i]);
//			if(nRet < 0)
//			{
//				return nRet;
//			}
//		}
//
//		return S_OK;
//	}
//	void Dump(char* buf, const uint32_t size, uint32_t& offset)
//	{
//		sprintf(buf + offset, "{nResult=0x%08x", nResult);
//		offset = (uint32_t)strlen(buf);
//		if(nResult != S_OK)
//		{
//			sprintf(buf + offset, "}");
//			offset = (uint32_t)strlen(buf);
//			return;
//		}
//
//		sprintf(buf + offset, ", nCount=%d,{", nCount);
//		offset = (uint32_t)strlen(buf);
//		for(int32_t i = 0; i < nCount; ++i)
//		{
//			sprintf(buf + offset, "nRoomID[%d]=%d, nRoleID[%d]=%d, nAccountID[%d]=%d, nMoney[%d]=%d, sRoleName[%d]=%s, nDate[%d]=%d, ",
//					i, nRoomID[i], i, nRoleID[i], i, nAccountID[i], i, nMoney[i], i, strRoleName[i].GetString(), i, nDate[i]);
//			offset = (uint32_t)strlen(buf);
//		}
//		sprintf(buf + offset, "}}");
//		offset = (uint32_t)strlen(buf);
//	}
//public:
//	int32_t		nResult;
//	int32_t		nCount;
//	RoomID		nRoomID[MaxRoomCountPerServer];	//房间ID
//	RoleID		nRoleID[MaxRoomCountPerServer];	//RoleID
//	AccountID	nAccountID[MaxRoomCountPerServer];	//179ID
//	uint32_t	nMoney[MaxRoomCountPerServer];	//单笔最大消费金额
//	CString<MaxRoleNameLength>		strRoleName[MaxRoomCountPerServer];	//昵称
//	int32_t		nDate[MaxRoomCountPerServer];	//日期  格式如:20121230
//};

//取得星玩家(幸运之星等)请求
#define MSGID_ISDB_GETSTARPLAYER_REQ				0x00110810
class CGetStarPlayerReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetStarPlayerReq()
	{
	}

	virtual ~CGetStarPlayerReq()
	{
	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nothing}");
		offset = (uint32_t)strlen(buf);
	}
};

//取得星玩家(幸运之星等)响应
#define MSGID_ISDB_GETSTARPLAYER_RESP				0x00120810
class CGetStarPlayerResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetStarPlayerResp()
	{
		nResult = 0;
		nCount = 0;
		for(int32_t i = 0; i < MaxIdentityCount; ++i)
		{
			nRoleID[i] = enmInvalidRoleID;
			nIdentity[i] = enmIdentityType_None;
		}
	}
	virtual ~CGetStarPlayerResp()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nIdentity[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nIdentity[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=0x%08x", nResult);
		offset = (uint32_t)strlen(buf);
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			return;
		}

		sprintf(buf + offset, ", nCount=%d,{", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "nRoleID[%d]=%d, nIdentity[%d]=%d, ", i, nRoleID[i], i, nIdentity[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t		nResult;
	int32_t		nCount;
	int32_t		nRoleID[MaxIdentityCount];
	int32_t		nIdentity[MaxIdentityCount];
};

//取得在线玩家资产请求
#define MSGID_ISDB_GETONLINEPLAYERMONEY_REQ		0x00110811
class CGetOnlinePlayerMoneyReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetOnlinePlayerMoneyReq()
	{
		nCount = 0;
		for(int32_t i = 0; i < MaxGetOnlinePlayerCount; ++i)
		{
			nRoleID[i] = enmInvalidRoleID;
		}
	}
	virtual ~CGetOnlinePlayerMoneyReq()
	{
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "nRoleID[%d]=%d, ", i, nRoleID[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "} }");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t	nCount;	//要获取的玩家资产个数
	RoleID	nRoleID[MaxGetOnlinePlayerLefMoneyCount]; //玩家RoleID
};

//取得在线玩家资产、富豪等级相关的响应
#define MSGID_ISDB_GETONLINEPLAYERMONEY_RESP		0x00120811
class CGetOnlinePlayerMoneyResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetOnlinePlayerMoneyResp()
	{
		nResult = 0;
		nCount = 0;
		for(int32_t i = 0; i < MaxGetOnlinePlayerCount; ++i)
		{
			nRoleID[i] = enmInvalidRoleID;
			nMoney[i] = 0;
			nMagnateLevel[i] = enmMagnateLevel_0;
			nConsumeAmt[i] = 0;
			nNextLevelConsume[i] = 0;
		}
	}
	virtual ~CGetOnlinePlayerMoneyResp()
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
		if(nCount > MaxGetOnlinePlayerLefMoneyCount)
		{
			return E_INVALID_ARGUMENTS;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nConsumeAmt[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nNextLevelConsume[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nCount > MaxGetOnlinePlayerLefMoneyCount)
		{
			return E_INVALID_ARGUMENTS;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nMagnateLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nConsumeAmt[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nNextLevelConsume[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=0x%08x, ", nResult);
		offset = (uint32_t)strlen(buf);
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			return;
		}

		sprintf(buf + offset, ", nCount=%d,", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; ++i)
		{
			sprintf(buf + offset, "{nRoleID[%d]=%d, nMoney[%d]=%u, nMagnateLevel[%d]=%d, nConsumeAmt[%d]=%lu, nNextLevelConsume[%d]=%lu}, ",
					i, nRoleID[i], i, nMoney[i], i, nMagnateLevel[i], i, nConsumeAmt[i], i, nNextLevelConsume[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, " }");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nResult; //错误码
	int32_t	nCount;	//要获取的玩家资产个数
	RoleID	nRoleID[MaxGetOnlinePlayerLefMoneyCount]; //玩家RoleID
	uint32_t nMoney[MaxGetOnlinePlayerLefMoneyCount];  //玩家资产
	MagnateLevel nMagnateLevel[MaxGetOnlinePlayerLefMoneyCount]; //富豪等级
	uint64_t nConsumeAmt[MaxGetOnlinePlayerLefMoneyCount]; //总消费额
	uint64_t nNextLevelConsume[MaxGetOnlinePlayerLefMoneyCount];  //下一富豪等级消费额
};

//取得房间沙发请求
#define MSGID_ISDB_GETSOFA_REQ		0x00110812
class CGetSofaReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetSofaReq()
	{
		nRoomID = enmInvalidRoomID;
	}
	virtual ~CGetSofaReq()
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
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d}", nRoomID);
		offset = (uint32_t)strlen(buf);
	}
public:
	RoomID	nRoomID;
};

//取得房间沙发响应
#define MSGID_ISDB_GETSOFA_RESP		0x00120812
class CGetSofaResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetSofaResp()
	{
		nResult = 0;
		nRoomID = enmInvalidRoomID;
		memset(nSofaPos, 0, sizeof(nSofaPos));
		memset(nSofaTicket, 0, sizeof(nSofaTicket));
		memset(nRoleID, 0, sizeof(nRoleID));
		memset(nAccountID, 0, sizeof(nAccountID));
		memset(nGender, 0, sizeof(nGender));
		memset(nVipLevel, 0, sizeof(nVipLevel));
		memset(nMagnateLevel, 0, sizeof(nMagnateLevel));
		memset(nUpdateTime, 0, sizeof(nUpdateTime));
		for(int32_t i = 0; i < ROOM_SOFACOUNT; i++)
		{
			arrStrRoleName[i].Initialize();
		}
	}
	virtual ~CGetSofaResp()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < ROOM_SOFACOUNT; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, nSofaPos[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nSofaTicket[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nAccountID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nGender[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nMagnateLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = arrStrRoleName[i].MessageEncode(buf, size, offset);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nUpdateTime[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < ROOM_SOFACOUNT; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, nSofaPos[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nSofaTicket[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nAccountID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nGender[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nMagnateLevel[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = arrStrRoleName[i].MessageDecode(buf, size, offset);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nUpdateTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=0x%08x, ", nResult);
		offset = (uint32_t)strlen(buf);
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			return;
		}

		sprintf(buf + offset, "nRoomID=%d, ", nRoomID);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < ROOM_SOFACOUNT; i++)
		{
			sprintf(buf + offset, "nSofaPos=%d, nSofaTicket=%u, nRoleID=%d, nAccountID=%d, nGender=%d, "
					"nVipLevel=%d, nMagnateLevel=%d, strRoleName=%s, nUpdateTime=%u, ",
					nSofaPos[i], nSofaTicket[i], nRoleID[i], nAccountID[i], nGender[i],
					nVipLevel[i], nMagnateLevel[i], arrStrRoleName[i].GetString(), nUpdateTime[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "} }");
		offset = (uint32_t)strlen(buf);
	}

public:
	int32_t			nResult;
	RoomID			nRoomID;
	uint8_t			nSofaPos[ROOM_SOFACOUNT];//第一个沙发的pos是1
	uint32_t		nSofaTicket[ROOM_SOFACOUNT];
	RoleID			nRoleID[ROOM_SOFACOUNT];
	AccountID		nAccountID[ROOM_SOFACOUNT];
	Gender			nGender[ROOM_SOFACOUNT];
	VipLevel		nVipLevel[ROOM_SOFACOUNT];
	MagnateLevel	nMagnateLevel[ROOM_SOFACOUNT];
	CString<MaxRoleNameLength>	arrStrRoleName[ROOM_SOFACOUNT];
	uint32_t		nUpdateTime[ROOM_SOFACOUNT];
};

//设置沙发协议
#define MSGID_ISDB_SETSOFA_NOTI		0x00130813
class CSetSofaNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetSofaNoti()
	{
		nType = enmOperateSofa_Invalid;
		nRoomID = enmInvalidRoomID;
		nSofaPos = 0;
		nSofaTicket = 0;
		nRoleID = enmInvalidRoleID;
		nUpdateTime = 0;
	}
	virtual ~CSetSofaNoti()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nType);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSofaPos);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSofaTicket);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nUpdateTime);
		if(nRet < 0)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nType);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSofaPos);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSofaTicket);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nUpdateTime);
		if(nRet < 0)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nType=%d, nRoomID=%d, nSofaPos=%d, nSofaTicket=%u, nRoleID=%d, nUpdateTime=%u }",
				nType, nRoomID, nSofaPos, nSofaTicket, nRoleID, nUpdateTime);
		offset = (uint32_t)strlen(buf);
	}
public:
	uint8_t nType;	//1设置 2清空。 设置的时候只对单个房间上单个沙发操作，清空的时候对所有房间清空
	int32_t nRoomID;
	uint8_t nSofaPos; //第一个沙发的pos是1
	uint32_t nSofaTicket; //某个位置上沙发花费的沙发券
	RoleID	 nRoleID;
	uint32_t nUpdateTime; //清空的时候UpdateTime写0
};

//取得幸运中奖玩家请求
#define MSGID_ISDB_GETLUCKYUSER_REQ	0x00110814
class CGetLuckyUserReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetLuckyUserReq()
	{
		nStartIndex = 0;
		nWantCount = 0;
	}
	virtual ~CGetLuckyUserReq()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nStartIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nStartIndex);
		if(nRet < 0)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nWantCount);
		if(nRet < 0)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nStartIndex=%d, nWantCount=%d}", nStartIndex, nWantCount);
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nStartIndex;
	int32_t nWantCount;
};

//取得幸运中奖玩家响应
#define MSGID_DBIS_GETLUCKYUSER_RESP	0x00120814
class CGetLuckyUserResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetLuckyUserResp()
	{
		nCount = 0;
		nResult = S_OK;
		for(int32_t i = 0; i < MaxPerGetLuckyUserCount; i++)
		{
			arrRoleID[i] = enmInvalidRoleID;
			arrItemID[i] = enmInvalidItemID;
			arrPrice[i] = 0;
			arrLuckyCount[i] = 0;
			arrLuckyTime[i] = 0;
		}
	}
	virtual ~CGetLuckyUserResp()
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
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrLuckyTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrLuckyCount[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrLuckyTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrLuckyCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "{nResult=%x}", nResult);
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "arrRoleID[%d]=%d, arrItemID[%d]=%d, arrPrice[%d]=%d, arrLuckyCount[%d]=%d, arrLuckyTime[%d]=%d, ",
				i, arrRoleID[i], i, arrItemID[i], i, arrPrice[i], i, arrLuckyCount[i], i, arrLuckyTime[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nResult;
	int32_t nCount;
	RoleID	arrRoleID[MaxPerGetLuckyUserCount];
	ItemID	arrItemID[MaxPerGetLuckyUserCount];
	int32_t arrLuckyTime[MaxPerGetLuckyUserCount];
	int32_t arrPrice[MaxPerGetLuckyUserCount];
	int32_t arrLuckyCount[MaxPerGetLuckyUserCount];
};

#define MSGID_ISDB_SETLUCKYUSER_NOTI	0x00130814
class CSetLuckyUserNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetLuckyUserNoti()
	{
		nCount = 0;
		for(int32_t i = 0; i < MaxPerGetLuckyUserCount; i++)
		{
			arrRoleID[i] = enmInvalidRoleID;
			arrItemID[i] = enmInvalidItemID;
			arrPrice[i] = 0;
			arrLuckyCount[i] = 0;
			arrLuckyTime[i] = 0;
		}
	}
	virtual ~CSetLuckyUserNoti()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrLuckyTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrLuckyCount[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrItemID[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrLuckyTime[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrLuckyCount[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "arrRoleID[%d]=%d, arrItemID[%d]=%d, arrPrice[%d]=%d, arrLuckyCount[%d]=%d, arrLuckyTime[%d]=%d, ",
				i, arrRoleID[i], i, arrItemID[i], i, arrPrice[i], i, arrLuckyTime[i], i, arrLuckyCount[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nCount;
	RoleID	arrRoleID[MaxPerGetLuckyUserCount];
	ItemID	arrItemID[MaxPerGetLuckyUserCount];
	int32_t arrLuckyTime[MaxPerGetLuckyUserCount];
	int32_t arrPrice[MaxPerGetLuckyUserCount];
	int32_t arrLuckyCount[MaxPerGetLuckyUserCount];
};

#define MSGID_ISDB_GETJACKPOTMONEY_REQ	0x00110815
class CGetJackpotMoneyReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetJackpotMoneyReq()
	{
	}
	virtual ~CGetJackpotMoneyReq()
	{
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{empty MsgBody}");
	}
public:

};

#define MSGID_DBIS_GETJACKPOTMONEY_RESP	0x00120815
class CGetJackpotMoneyResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetJackpotMoneyResp()
	{
		nResult = 0;
		nCount = 0;
		memset(arrPrice, 0, sizeof(arrPrice));
		memset(arrMultipe, 0, sizeof(arrMultipe));
		memset(arrMoney, 0, sizeof(arrMoney));
	}
	virtual ~CGetJackpotMoneyResp()
	{
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if(nRet < 0)
		{
			return nRet;
		}
		if(nResult != S_OK)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		if(nResult != S_OK)
		{
			sprintf(buf + offset, "{nResult=%x}", nResult);
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "arrPrice[%d]=%d, arrMultipe[%d]=%d, arrnMoney[%d]=%d, ",
				i, arrPrice[i], i, arrMultipe[i], i, arrMoney[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nResult;
	int32_t nCount;
	int32_t arrPrice[MaxPerGetLuckyUserCount];
	int32_t arrMultipe[MaxPerGetLuckyUserCount];
	int32_t arrMoney[MaxPerGetLuckyUserCount];
};

#define MSGID_ISDB_SETJACKPOTMONEY_NOTI	0x00130815
class CSetJackpotMoneyNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSetJackpotMoneyNoti()
	{
		nCount = 0;
		memset(arrnPrice, 0, sizeof(arrnPrice));
		memset(arrMultipe, 0, sizeof(arrMultipe));
		memset(arrnMoney, 0, sizeof(arrnMoney));
	}
	virtual ~CSetJackpotMoneyNoti()
	{
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrnPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrnMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}

		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if(nRet < 0)
		{
			return nRet;
		}
		for(int32_t i = 0; i < nCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrnPrice[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrMultipe[i]);
			if(nRet < 0)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrnMoney[i]);
			if(nRet < 0)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "arrnPrice[%d]=%d, arrMultipe[%d]=%d, arrnMoney[%d]=%d, ",
				i, arrnPrice[i], i, arrMultipe[i], i, arrnMoney[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "}}");
		offset = (uint32_t)strlen(buf);
	}
public:
	int32_t nCount;
	int32_t arrnPrice[MaxPerGetLuckyUserCount];
	int32_t arrMultipe[MaxPerGetLuckyUserCount];
	int32_t arrnMoney[MaxPerGetLuckyUserCount];
};

MESSAGEMAP_DECL_BEGIN(itemserver)

MESSAGEMAP_DECL_MSG(MSGID_ISDB_BATCHUPDATEASSET_REQ, (new CBatchUpdateAssetReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_BATCHUPDATEASSET_RESP, (new CBatchUpdateAssetResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_UPDATEITEM_REQ, (new CUpdateItemReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_UPDATEITEM_RESP, (new CUpdateItemResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETROLEITEMINFO_REQ, (new CGetRoleItemInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETROLEITEMINFO_RESP, (new CGetRoleItemInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETITEMJACKPOTINFO_REQ, (new CGetItemJackpotInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETITEMJACKPOTINFO_RESP, (new CGetItemJackpotInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETITEMJACKPOTINFO_REQ, (new CSetItemJackpotInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_ISRS_NEEDREBULID_NOTICE, (new CNeedRebulidNotice()))
MESSAGEMAP_DECL_MSG(MSGID_ISHS_GETONLINEPLAYERINFOINFO_REQ, (new CGetOnlinePlayerInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_HSIS_GETONLINEPLAYERINFOINFO_RESP, (new CGetOnlinePlayerInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETSTOREPOOLINFO_REQ, (new CSetStorePoolInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_SETSTOREPOOLINFO_RESP, (new CSetStorePoolInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETSTOREPOOLINFO_REQ, (new CGetStorePoolInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETSTOREPOOLINFO_RESP, (new CGetStorePoolInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISRS_BIGCONSUME_NOTI, (new CBigConsumeNoti()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETROLEPACKSACKINFO_REQ, (new CGetRolePackSackInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETROLEPACKSACKINFO_RESP, (new CGetRolePackSackInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_UPDATEGOOD_REQ, (new CUpdateGoodReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_UPDATEGOOD_RESP, (new CUpdateGoodResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISOS_UPDATEIDENTITY_NOTI, (new CUpdateIdentityNoti()))
//MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETONCEMAXSPEND_NOTICE, (new CSetOnceMaxSpendNoti()))
//MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETONCEMAXSPEND_REQ, (new CGetOnceMaxSpendReq()))
//MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETONCEMAXSPEND_RESP, (new CGetOnceMaxSpendResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETSTARPLAYER_REQ, (new CGetStarPlayerReq()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETSTARPLAYER_RESP, (new CGetStarPlayerResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETONLINEPLAYERMONEY_REQ, (new CGetOnlinePlayerMoneyReq()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETONLINEPLAYERMONEY_RESP, (new CGetOnlinePlayerMoneyResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETSOFA_REQ, (new CGetSofaReq()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETSOFA_RESP, (new CGetSofaResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETSOFA_NOTI, (new CSetSofaNoti()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETLUCKYUSER_REQ, (new CGetLuckyUserReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETLUCKYUSER_RESP, (new CGetLuckyUserResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETLUCKYUSER_NOTI, (new CSetLuckyUserNoti()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_GETJACKPOTMONEY_REQ, (new CGetJackpotMoneyReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBIS_GETJACKPOTMONEY_RESP, (new CGetJackpotMoneyResp()))
MESSAGEMAP_DECL_MSG(MSGID_ISDB_SETJACKPOTMONEY_NOTI, (new CSetJackpotMoneyNoti()))

MESSAGEMAP_DECL_END()




FRAME_NAMESPACE_END

#endif /* ITEMSERVER_MESSAGE_DEFINE_H_ */
