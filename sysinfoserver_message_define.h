/*
 * sysinfoserver_message_define.h
 *
 *  Created on: 2012-3-2
 *      Author: fuz
 */

#ifndef SYSINFOSERVER_MESSAGE_DEFINE_H_
#define SYSINFOSERVER_MESSAGE_DEFINE_H_

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_protocolhead.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include "common/common_datetime.h"
#include "common/common_def.h"
#include "public_message_define.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

// the req from background
#define MSGID_BGSS_SYSINFO_REQ			0x00100D01
class CSysInfoReq_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSysInfoReq_Public()
	{
		nInfoType = 0;
		arrInfoBuff.Initialize();
	}
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nInfoType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = arrInfoBuff.MessageEncode(buf, size, offset);
		if(0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nInfoType);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = arrInfoBuff.MessageDecode(buf, size, offset);
		if(0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nInfoType=%d,arrInfoBuff=%s}", nInfoType,
				arrInfoBuff.GetString());
		offset = (uint32_t) strlen(buf);
	}
public:
	uint16_t nInfoType;
	CString<MaxInfoSize> arrInfoBuff;
};

// the response to background
#define MSGID_SSBG_SYSINFO_RESP			0x00130D01
class CSysInfoResp_Public: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CSysInfoResp_Public()
	{
		nResult = 0;
	}
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
		sprintf(buf + offset, "{nResult=%d}", nResult);
		offset = (uint32_t) strlen(buf);
	}
public:
	int32_t nResult;
};

class SingleRoleConsump
{
public:
	SingleRoleConsump()
	{
		Initialize();
	}
	void Initialize()
	{
		nRoleID = enmInvalidRoleID;
		nSupplymentTotal = 0;
	}
	RoleID nRoleID;
	int32_t nSupplymentTotal;
};

// request of getting players' supplyment between XX - XX time
#define MSGID_SSDS_SYPPLYMENT_REQ		0x00110D03
class CGetSupplymentReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nRoleCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return nRet;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nRoleCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{this is the get supplyment info request msgbody: nRoleCount=%d, RoleID=%d... between time:%lu and %lu\n}",
				nRoleCount, arrRoleID[0], nStartTime, nEndTime);
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetSupplymentReq()
	{
		nRoleCount = 0;
		for (uint32_t i = 0; i < UserCountEveryTime; i++)
		{
			arrRoleID[i] = enmInvalidRoleID;
		}
		nStartTime = enmInvalidTimeVal;
		nEndTime = enmInvalidTimeVal;
	}
	virtual ~CGetSupplymentReq() {}

public:
	uint32_t nRoleCount;
	RoleID arrRoleID[UserCountEveryTime];
	uint64_t nStartTime;
	uint64_t nEndTime;
};

// the response of players' supplyment
#define MSGID_DSSS_SYPPLYMENT_RESP		0x00120D03
class CGetSupplymentResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < UserCountEveryTime; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrRoleConsump[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrRoleConsump[i].nSupplymentTotal);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < UserCountEveryTime; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrRoleConsump[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrRoleConsump[i].nSupplymentTotal);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		} else
		{
			sprintf(buf + offset,
					"\nnResultCount=%d, \nnRoleID=%d...,\nnSupplymentTotal=%d...}\n",
					nResultCount, arrRoleConsump[0].nRoleID,
					arrRoleConsump[0].nSupplymentTotal);
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetSupplymentResp()
	{
		nResult = enmDefault_ErrorCode;
		nResultCount = 0;

		for (uint32_t i = 0; i < UserCountEveryTime; i++)
		{
			arrRoleConsump[i].Initialize();
		}
	}
	virtual ~CGetSupplymentResp() {}

public:
	int32_t nResult;
	uint32_t nResultCount;
	SingleRoleConsump arrRoleConsump[UserCountEveryTime];
};

class SingleRoleInfo: public SingleRoleConsump
{
public:
	SingleRoleInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nVipLevel = enmInvalidVipLevel;
	}
	VipLevel nVipLevel;
};

// request of getting vip players' infor for  (>= nVipLevel) and (< nBeingVipTime), and supplyment sum between XX and XX time
#define MSGID_SSDS_VIPINFO_REQ			0x00110D04
class CGetVipRoleReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nBeingVipTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nBegin);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return nRet;
	}

	int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nBeingVipTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nBegin);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nStartTime);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEndTime);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf( buf + offset,
				"{this is the get VipRole info request msgbody: nVipLevel=%d, nBeingVipTime=%ld, begin=%u, limit=%u, start=%ld, end=%ld\n}",
				nVipLevel, nBeingVipTime, nBegin, nLimit, nStartTime, nEndTime);
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetVipRoleReq()
	{
		nVipLevel = enmInvalidLevel;
		nBeingVipTime = enmInvalidTimeVal;
		nBegin = 0;
		nLimit = 0;
		nStartTime = enmInvalidTimeVal;
		nEndTime = enmInvalidTimeVal;
	}
	virtual ~CGetVipRoleReq() {}

public:
	VipLevel nVipLevel;
	int64_t nBeingVipTime; // the former and former month timestamp, if to-month is 5, the being vip time should < 1st of 4
	uint32_t nBegin;
	uint32_t nLimit;
	int64_t nStartTime;// begin time to calculate
	int64_t nEndTime;// end time to calculate
};

// response of getting vip players' info
#define MSGID_DSSS_VIPINFO_RESP			0x00120D04
class CGetVipInfoResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrVipInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrVipInfo[i].nVipLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrVipInfo[i].nSupplymentTotal);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrVipInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrVipInfo[i].nVipLevel);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrVipInfo[i].nSupplymentTotal);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	//void Dump(char* buf, const uint32_t size, uint32_t& offset)
	//{
	//	sprintf(buf + offset, "{nResult=%d,", nResult);
	//	offset = (uint32_t) strlen(buf);
	//	if (nResult < 0)
	//	{
	//		sprintf(buf + offset, "}");
	//	} else
	//	{
	//		sprintf( buf + offset,
	//				"\nnResultCount=%d, \nnRoleID=%d...,\nnSupplymentTotal=%d..., \nnVipLevel=%d...}\n",
	//				nResultCount, arrVipInfo[0].nRoleID,
	//				arrVipInfo[0].nSupplymentTotal, arrVipInfo[0].nVipLevel);
	//	}

	//	offset = (uint32_t) strlen(buf);
	//}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d", nResult);
		if(0 > nResult)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, ", nResultCount=%d, ", nResultCount);
		offset = (uint32_t)strlen(buf);
		if(0 == nResultCount)
		{
			return;
		}
		for(uint32_t i=0; i<nResultCount - 1; ++i)
		{
			sprintf(buf + offset, "{nVipLevel[%d]=%d, nRoleID[%d]=%d, nSupplymentTotal[%d]=%d}, ", 
				i, arrVipInfo[i].nVipLevel, 
				i, arrVipInfo[i].nRoleID, 
				i, arrVipInfo[i].nSupplymentTotal);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "{nVipLevel[%d]=%d, nRoleID[%d]=%d, nSupplymentTotal[%d]=%d}}\n", 
			nResultCount - 1, arrVipInfo[nResultCount - 1].nVipLevel, 
			nResultCount - 1, arrVipInfo[nResultCount - 1].nRoleID, 
			nResultCount - 1, arrVipInfo[nResultCount - 1].nSupplymentTotal);
		offset = (uint32_t)strlen(buf);
	}

public:
	CGetVipInfoResp()
	{
		nResult = enmDefault_ErrorCode;
		nResultCount = 0;

		for (uint32_t i = 0; i < MaxDegradeCountEveryTime; i++)
		{
			arrVipInfo[i].Initialize();
		}
	}
	virtual ~CGetVipInfoResp() {}

public:
	int32_t nResult;
	uint32_t nResultCount;
	SingleRoleInfo arrVipInfo[MaxDegradeCountEveryTime];
};

// request of degrading one player
#define MSGID_SSDS_DEGRADE_REQ			0x00110D05
class CDegradeReq: public IMsgBody
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
		nRet = CCodeEngine::Encode(buf, size, offset, nDegradeLevel);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nDegradeLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf( buf + offset,
				"{this is the Degrade VipLevel request msgbody: nRoleID=%d, nDegradeLevel=%u}\n",
				nRoleID, nDegradeLevel);
		offset = (uint32_t) strlen(buf);
	}
public:
	CDegradeReq()
	{
		nRoleID = enmInvalidRoleID;
		nDegradeLevel = 0;

	}
	virtual ~CDegradeReq() {}

public:
	RoleID nRoleID;
	uint8_t nDegradeLevel;// logic vip level fall, like between [gold king] <-> [silver king]
};

// response of degrading
#define MSGID_DSSS_DEGRADE_RESP			0x00120D05
class CDegradeResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
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
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		} else
		{
			sprintf(buf + offset, "\nnRoleID=%d, nVipLevel=%u}\n", nRoleID,
					nVipLevel);
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CDegradeResp()
	{
		nResult = enmDefault_ErrorCode;
		nRoleID = enmInvalidRoleID;
		nVipLevel = enmInvalidVipLevel;
	}
	virtual ~CDegradeResp() {}

public:
	int32_t nResult;
	RoleID nRoleID;
	VipLevel nVipLevel;
};

class DegradeInfo
{
public:
	DegradeInfo()
	{
		nRoleID = enmInvalidRoleID;
		nDegradeLevel = 0;
	}
	RoleID nRoleID;
	// logic vip level fall, like between [gold king] <-> [silver king]
	uint8_t nDegradeLevel;
};
// request of degrading group player
#define MSGID_SSDS_GROUPDEGRADE_REQ		0x00110D07
class CGroupDegradeReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (int32_t i = 0; i < nCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrPreVipLevel[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrCurVipLevel[i]);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (int32_t i = 0; i < nCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrPreVipLevel[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrCurVipLevel[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf( buf + offset, "{nCount=%d, {", nCount);
		offset = (uint32_t)strlen(buf);

		for (int32_t i = 0; i < nCount; i++)
		{
			sprintf(buf + offset, "arrRoleID[%d]=%d, arrPreVipLevel[%d]=%d, arrCurVipLevel[%d]=%d, ",
					i, arrRoleID[i], i, arrPreVipLevel[i], i, arrCurVipLevel[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf + offset, "} }");
		offset = (uint32_t) strlen(buf);
	}
public:
	CGroupDegradeReq()
	{
		nCount = 0;
		for (int32_t i = 0; i < MaxDegradeCountEveryTime; i++)
		{
			arrRoleID[i] = enmInvalidRoleID;
			arrPreVipLevel[i] = enmInvalidVipLevel;
			arrCurVipLevel[i] = enmInvalidVipLevel;
		}
	}
	virtual ~CGroupDegradeReq() {}

public:
	int32_t  nCount;
	RoleID	 arrRoleID[MaxDegradeCountEveryTime];
	VipLevel arrPreVipLevel[MaxDegradeCountEveryTime];	//降级前的VipLevel
	VipLevel arrCurVipLevel[MaxDegradeCountEveryTime];	//降级后的VipLevel
};

class VipLevelInfo
{
public:
	VipLevelInfo()
	{
		nRoleID = enmInvalidRoleID;
		nVipLevel = enmInvalidVipLevel;
	}
	RoleID nRoleID;
	VipLevel nVipLevel;
};

// response of degrading group player
#define MSGID_DSSS_GROUPDEGRADE_RESP	0x00120D07
class CGroupDegradeResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (int32_t i = 0; i < nCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, arrVipLevel[i]);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (int32_t i = 0; i < nCount && i < MaxDegradeCountEveryTime; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, arrVipLevel[i]);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
			offset = (uint32_t) strlen(buf);
		}
		else
		{
			sprintf(buf + offset, "{nCount=%d, {", nCount);
			offset = (uint32_t) strlen(buf);
			for (int32_t i = 0; i < nCount; i++)
			{
				sprintf(buf + offset, "RoleID[%d]=%d,VipLevel[%d]=%d,", i, arrRoleID[i], i, arrVipLevel[i]);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "} }");
			offset = (uint32_t) strlen(buf);
		}
	}
public:
	CGroupDegradeResp()
	{
		nResult = enmDefault_ErrorCode;
		nCount = 0;
		for (int32_t i = 0; i < MaxDegradeCountEveryTime; i++)
		{
			arrRoleID[i] = enmInvalidRoleID;
			arrVipLevel[i] = enmInvalidVipLevel;
		}
	}
	virtual ~CGroupDegradeResp() {}

public:
	int32_t nResult;
	int32_t nCount;
	RoleID arrRoleID[MaxDegradeCountEveryTime];
	VipLevel arrVipLevel[MaxDegradeCountEveryTime];
};

// request of getting user rank list info
#define MSGID_SSDS_RANK_REQ				0x00110D08
class CRankInfoReq: public IMsgBody
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
		sprintf(buf + offset, "{this is the get rank info request msgbody}");
		offset = (uint32_t) strlen(buf);
	}
public:
	CRankInfoReq() {}
	virtual ~CRankInfoReq() {}
};

class RankListInfo
{
public:
	RoleID nRoleID; // 用户uin
	RankListType nRankListType;// 排行榜类型
	uint32_t nPlace; //排行名次
	RankListInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nRoleID = enmInvalidRoleID;
		nRankListType = enmRankType_InvalidType;
		nPlace = 0;
	}
};

class GiftStarInfo
{
public:
	RoleID nRoleID; // 用户uin
	ItemID nItemID;// 礼物之星ID
	uint32_t nGiftCount; //礼物数量
	GiftStarInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nRoleID = enmInvalidRoleID;
		nItemID = enmInvalidItemID;
		nGiftCount = 0;
	}
};

// response of getting user rank list info
#define MSGID_DSSS_RANK_RESP			0x00120D08
class CRankInfoResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRankListCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nRankListCount && i < MaxRankListTypes; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayRankListInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayRankListInfo[i].nRankListType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayRankListInfo[i].nPlace);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nGiftStarCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nGiftStarCount && i < MaxGiftStarCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayGiftStarInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayGiftStarInfo[i].nItemID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrayGiftStarInfo[i].nGiftCount);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRankListCount);
		if (0 > nRet)
		{
			return nRet;
		}

		for (uint32_t i = 0; i < nRankListCount && i < MaxRankListTypes; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayRankListInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayRankListInfo[i].nRankListType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayRankListInfo[i].nPlace);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nGiftStarCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nGiftStarCount && i < MaxGiftStarCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayGiftStarInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayGiftStarInfo[i].nItemID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrayGiftStarInfo[i].nGiftCount);
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
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}\n");
			return;
		}

		sprintf(buf + offset, "}, {nRankListCount=%d}", nRankListCount);
		offset = (uint32_t) strlen(buf);
		if(nRankListCount <= 0)
			return;
		sprintf(buf + offset, ", {");
		offset = (uint32_t) strlen(buf);
		for (uint32_t i = 0; i < nRankListCount; i++)
		{
			char* fmt = NULL;
			if(i < nRankListCount - 1)
				fmt = "{nRoleID=%d, nRankListType=%d, nPlace=%u}, ";
			else
				fmt = "{nRoleID=%d, nRankListType=%d, nPlace=%u}}";
			sprintf(buf + offset, fmt, arrayRankListInfo[i].nRoleID,
					arrayRankListInfo[i].nRankListType,
					arrayRankListInfo[i].nPlace);
			offset = (uint32_t) strlen(buf);
		}

		sprintf(buf + offset, ", {nGiftStarCount=%d}", nGiftStarCount);
		offset = (uint32_t) strlen(buf);
		if(nGiftStarCount <= 0)
			return;
		sprintf(buf + offset, ", {");
		offset = (uint32_t) strlen(buf);
		for (uint32_t i = 0; i < nGiftStarCount; i++)
		{
			char* fmt = NULL;
			if(i < nGiftStarCount - 1)
				fmt = "{nRoleID=%d, nItemID=%d, nGiftCount=%u}, ";
			else
				fmt = "{nRoleID=%d, nItemID=%d, nGiftCount=%u}}";
			sprintf(buf + offset, fmt, arrayGiftStarInfo[i].nRoleID,
					arrayGiftStarInfo[i].nItemID,
					arrayGiftStarInfo[i].nGiftCount);
			offset = (uint32_t) strlen(buf);
		}

		sprintf(buf + offset, "}\n");
		offset = (uint32_t) strlen(buf);
	}
public:
	CRankInfoResp()
	{
		nResult = enmDefault_ErrorCode;
		nRankListCount = 0;
		nGiftStarCount = 0;
		for (uint32_t i = 0; i < MaxRankListTypes; i++)
		{
			arrayRankListInfo[i].Initialize();
		}
		for (uint32_t i = 0; i < MaxGiftStarCount; i++)
		{
			arrayGiftStarInfo[i].Initialize();
		}
	}
	virtual ~CRankInfoResp() {}

public:
	int32_t nResult;
	uint32_t nRankListCount;
	RankListInfo arrayRankListInfo[MaxRankListTypes];
	uint32_t nGiftStarCount;
	GiftStarInfo arrayGiftStarInfo[MaxGiftStarCount];
};

// request of inserting a new msg to db
#define MSGID_SSDS_NEWMSG_REQ			0x00110D09
class CNewMessageReq: public IMsgBody
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
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = szMsgContent.MessageEncode(buf, size, offset);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = szMsgContent.MessageDecode(buf, size, offset);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{this is the new message request msgbody: nRoleID=%u, nChannelType=%u, szMsgContent=%s }\n",
				nRoleID, nChannelType, szMsgContent.GetString());
		offset = (uint32_t) strlen(buf);
	}
public:
	CNewMessageReq()
	{
		nRoleID = enmInvalidRoleID;
		nChannelType = enumSysChannelType_Invalid;
		szMsgContent.Initialize();
	}
	virtual ~CNewMessageReq() {}

public:
	RoleID nRoleID;
	SysChannelType nChannelType;
	CString<MaxMsgContentLen> szMsgContent;
};

// response of inserting a new msg to db
#define MSGID_DSSS_NEWMSG_RESP			0x00120D09
class CNewMessageResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
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
		nRet = CCodeEngine::Decode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		}
		else
		{
			sprintf(buf + offset, "\nnRoleID=%u}\n", nRoleID);
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CNewMessageResp()
	{
		nResult = enmDefault_ErrorCode;
		nRoleID = enmInvalidRoleID;
	}
	virtual ~CNewMessageResp() {}

public:
	int32_t nResult;
	RoleID nRoleID;
};

// request of getting given channel's msg of sb, limit nBegin, nLimit
#define MSGID_SSDS_GETMSG_REQ			0x00110D0A
class CGetMessageReq: public IMsgBody
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
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nReaded);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nBegin);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nLimit);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nReaded);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nBegin);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nLimit);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{this is the get message request msgbody: nRoleID=%u, "
					"\nnChannelType=%u, \nnReaded=%u, \nnBegin=%u, \nnLimit=%u}\n",
				nRoleID, nChannelType, nReaded, nBegin, nLimit);
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetMessageReq()
	{
		nRoleID = enmInvalidRoleID;
		nChannelType = enumSysChannelType_Invalid;
		nReaded = 0;
		nBegin = 0;
		nLimit = 0;
	}
	virtual ~CGetMessageReq() {}

public:
	RoleID nRoleID;
	SysChannelType nChannelType;
	uint8_t nReaded;//0(non-readed), 1(readed), 2(total)
	uint32_t nBegin;
	uint32_t nLimit;
};

// complete msg info
class MsgInfo
{
public:
	uint32_t nMsgID;
	RoleID nRoleID;
	SysChannelType nChannelType;
	CString<MaxMsgContentLen> szMsgContent;
	uint8_t nReaded;
	uint32_t nMsgdate;
	MsgInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nMsgID = 0;
		nRoleID = enmInvalidRoleID;
		nChannelType = enumSysChannelType_Invalid;
		szMsgContent.Initialize();
		nReaded = 0;
		nMsgdate = 0;
	}
};

// response of geting new msgs from db
#define MSGID_DSSS_GETMSG_RESP			0x00120D0A
class CGetMessageResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxGetMsgCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrMsgInfos[i].nMsgID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrMsgInfos[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrMsgInfos[i].nChannelType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrMsgInfos[i].szMsgContent.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrMsgInfos[i].nReaded);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrMsgInfos[i].nMsgdate);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxGetMsgCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrMsgInfos[i].nMsgID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrMsgInfos[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrMsgInfos[i].nChannelType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrMsgInfos[i].szMsgContent.MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrMsgInfos[i].nReaded);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrMsgInfos[i].nMsgdate);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		}
		else
		{
			sprintf(buf + offset, "\nnRoleID=%u, \nnResultCount=%d\n", nRoleID,
					nResultCount);
			offset = (uint32_t) strlen(buf);
			for (uint32_t i = 0; i < nResultCount; i++)
			{
				sprintf(buf + offset,
						"\narrMsgInfos[%d].nMsgID=%u, \nnRoleID=%u, \nnChannelType=%u,"
							" \nszMsgContent=%s, \nnReaded=%u, \nnMsgdate=%u",
						i, arrMsgInfos[i].nMsgID, arrMsgInfos[i].nRoleID,
						arrMsgInfos[i].nChannelType,
						arrMsgInfos[i].szMsgContent.GetString(),
						arrMsgInfos[i].nReaded, arrMsgInfos[i].nMsgdate);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "}\n");
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetMessageResp()
	{
		nResult = enmDefault_ErrorCode;
		nRoleID = enmInvalidRoleID;
		nResultCount = 0;
		for (uint32_t i = 0; i < MaxGetMsgCount; i++)
		{
			arrMsgInfos[i].Initialize();
		}
	}
	virtual ~CGetMessageResp() {}

public:
	int32_t nResult;
	RoleID nRoleID;
	uint32_t nResultCount;
	MsgInfo arrMsgInfos[MaxGetMsgCount];
};

// request of getting sb' given channel's msgs' count
#define MSGID_SSDS_GETMSGCNT_REQ		0x00110D0B
class CGetMessageCountReq: public IMsgBody
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
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nReaded);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nReaded);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{this is the get message count request msgbody: nRoleID=%u, "
					"\nnChannelType=%u, \nnReaded=%u}\n", nRoleID,
				nChannelType, nReaded);
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetMessageCountReq()
	{
		nRoleID = enmInvalidRoleID;
		nChannelType = enumSysChannelType_Invalid;
		nReaded = 0;
	}
	virtual ~CGetMessageCountReq(){}

public:
	RoleID nRoleID;
	SysChannelType nChannelType;
	uint8_t nReaded;//0(non-read), 1(read), 2(total)
};

// response of geting new msgs' count from db
#define MSGID_DSSS_GETMSGCNT_RESP		0x00120D0B
class CGetMessageCountResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nReaded);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nMsgCount);
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
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nChannelType);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nReaded);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nMsgCount);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		} else
		{
			sprintf(buf + offset,
					"\nnRoleID=%u, \nnChannelType=%d, \nnReaded=%d, \nnMsgCount=%d\n",
					nRoleID, nChannelType, nReaded, nMsgCount);
			offset = (uint32_t) strlen(buf);
			sprintf(buf + offset, "}\n");
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetMessageCountResp()
	{
		nResult = enmDefault_ErrorCode;
		nRoleID = enmInvalidRoleID;
		nChannelType = enumSysChannelType_Invalid;
		nReaded = 0;
		nMsgCount = 0;
	}
	virtual ~CGetMessageCountResp() {}

public:
	int32_t nResult;
	RoleID nRoleID;
	SysChannelType nChannelType;
	uint8_t nReaded;//0(non-read), 1(read), 2(total)
	uint32_t nMsgCount;
};

// request of getting system notice version
#define MSGID_SSDS_GETNOTICEVER_REQ		0x00110D0C
class CGetNoticeVersionReq: public IMsgBody
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
		sprintf(buf + offset,
				"{this is the get system notice version request msgbody");
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetNoticeVersionReq() {}
	virtual ~CGetNoticeVersionReq() {}
};

// response of getting system notice version
#define MSGID_DSSS_GETNOTICEVER_RESP	0x00120D0C
class CGetNoticeVersionResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nVersion);
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
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nVersion);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{CGetNoticeVersionResp, nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		}
		else
		{
			sprintf(buf + offset, " nVersion=%u", nVersion);
			offset = (uint32_t) strlen(buf);
			sprintf(buf + offset, "}\n");
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetNoticeVersionResp()
	{
		nResult = enmDefault_ErrorCode;
		nVersion = 0;
	}
	virtual ~CGetNoticeVersionResp() {}

public:
	int32_t nResult;
	int32_t nVersion;
};

// request of getting running system notice content
#define MSGID_SSDS_GETNOTICE_REQ		0x00110D0D
class CGetNoticeReq: public IMsgBody
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
		sprintf(buf + offset,
				"{this is the get running system notice content request msgbody");
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetNoticeReq() {}
	virtual ~CGetNoticeReq() {}
};

class SysNotice
{
public:
	int32_t nID;
	CString<MaxNoticeTitleLen> strTitle;
	CString<MaxMsgContentLen>  strContent;
	SysNoticeType nType;
	int64_t nStartTime;
	int64_t nEndTime;
	SysNoticeFlag nFlag;
	int32_t nLoopTime;
	int8_t	nSendFlag;
	SysNotice()
	{
		Initialize();
	}
	void Initialize()
	{
		nID = 0;
		strTitle.Initialize();
		strContent.Initialize();
		nType = enmSysNoticeType_None;
		nStartTime = enmInvalidTimeVal;
		nEndTime = enmInvalidTimeVal;
		nFlag = enmSysNoticeFlag_Unreaded;
		nLoopTime = enmInvalidTimeVal;
		nSendFlag = 0;
	}
	SysNotice& operator=(const SysNotice& otherSysNotice)
	{
		this->nID = otherSysNotice.nID;
		this->strTitle = otherSysNotice.strTitle;
		this->strContent = otherSysNotice.strContent;
		this->nType = otherSysNotice.nType;
		this->nStartTime = otherSysNotice.nStartTime;
		this->nEndTime = otherSysNotice.nEndTime;
		this->nFlag = otherSysNotice.nFlag;
		this->nLoopTime = otherSysNotice.nLoopTime;
		this->nSendFlag = otherSysNotice.nSendFlag;
		return *this;
	}
};

// response of getting running system notice content
#define MSGID_DSSS_GETNOTICE_RESP		0x00120D0D
class CGetNoticeResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxNoticeCount; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSysNotice[i].strTitle.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSysNotice[i].strContent.MessageEncode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nStartTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nEndTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nFlag);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nLoopTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrSysNotice[i].nSendFlag);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < MaxNoticeCount; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSysNotice[i].strTitle.MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = arrSysNotice[i].strContent.MessageDecode(buf, size, offset);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nType);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nStartTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nEndTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nFlag);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nLoopTime);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrSysNotice[i].nSendFlag);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d", nResult);
		offset = (uint32_t)strlen(buf);
		if(0 > nResult)
		{
			sprintf(buf + offset, "}\n");
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, ", nResultCount=%d", nResultCount);
		offset = (uint32_t)strlen(buf);
		if(0 == nResultCount)
		{
			sprintf(buf + offset, "}\n");
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, "{");
		offset = (uint32_t)strlen(buf);
		char szStartDateTime[enmMaxDateTimeStringLength] = {0};
		char szEndDateTime[enmMaxDateTimeStringLength] = {0};
		CDateTime dt;
		for(uint32_t i=0; i<nResultCount - 1; ++i)
		{
			memset(szStartDateTime, 0, sizeof(szStartDateTime));
			memset(szEndDateTime, 0, sizeof(szEndDateTime));
			dt = CDateTime(arrSysNotice[i].nStartTime * US_PER_SECOND);
			dt.ToDateTimeString(szStartDateTime);
			dt = CDateTime(arrSysNotice[i].nEndTime * US_PER_SECOND);
			dt.ToDateTimeString(szEndDateTime);
			sprintf(buf + offset, 
				", {nID[%d]=%d, "
				"strTitle[%d]=%s, "
				"strContent[%d]=%s, "
				"nSysNoticeType[%d]=%d, "
				"szStartTime[%d]=%s, "
				"szEndTime[%d]=%s, "
				"nSysNoticeFlag[%d]=%d, "
				"nLoopTime[%d]=%d, "
				"nSendFlag[%d]=%d}, ", 
				i, arrSysNotice[i].nID, 
				i, arrSysNotice[i].strTitle.GetString(),
				i, arrSysNotice[i].strContent.GetString(),
				i, arrSysNotice[i].nType, 
				i, szStartDateTime, 
				i, szEndDateTime, 
				i, arrSysNotice[i].nFlag, 
				i, arrSysNotice[i].nLoopTime, 
				i, arrSysNotice[i].nSendFlag);
			offset  = (uint32_t)strlen(buf);
		}
		memset(szStartDateTime, 0, sizeof(szStartDateTime));
		memset(szEndDateTime, 0, sizeof(szEndDateTime));
		dt = CDateTime(arrSysNotice[nResultCount - 1].nStartTime * US_PER_SECOND);
		dt.ToDateTimeString(szStartDateTime);
		dt = CDateTime(arrSysNotice[nResultCount - 1].nEndTime * US_PER_SECOND);
		dt.ToDateTimeString(szEndDateTime);
		sprintf(buf + offset, 
			"{nID[%d]=%d, "
			"strTitle[%d]=%s, "
			"strContent[%d]=%s, "
			"nSysNoticeType[%d]=%d, "
			"szStartTime[%d]=%s, "
			"szEndTime[%d]=%s, "
			"nSysNoticeFlag[%d]=%d, "
			"nLoopTime[%d]=%d, "
			"nSendFlag[%d]=%d}}\n",
			nResultCount - 1, arrSysNotice[nResultCount - 1].nID, 
			nResultCount - 1, arrSysNotice[nResultCount - 1].strTitle.GetString(),
			nResultCount - 1, arrSysNotice[nResultCount - 1].strContent.GetString(),
			nResultCount - 1, arrSysNotice[nResultCount - 1].nType,
			nResultCount - 1, szStartDateTime, 
			nResultCount - 1, szEndDateTime,
			nResultCount - 1, arrSysNotice[nResultCount - 1].nFlag,
			nResultCount - 1, arrSysNotice[nResultCount - 1].nLoopTime, 
			nResultCount - 1, arrSysNotice[nResultCount - 1].nSendFlag);
		offset = (uint32_t)strlen(buf);
	}
public:
	CGetNoticeResp()
	{
		nResult = enmDefault_ErrorCode;
		for (uint32_t i = 0; i < MaxNoticeCount; i++)
		{
			arrSysNotice[i].Initialize();
		}
	}
	virtual ~CGetNoticeResp() {}

public:
	int32_t nResult;
	uint32_t nResultCount;
	SysNotice arrSysNotice[MaxNoticeCount];
};

// request of clearing the timeout glory vip
#define MSGID_SSDS_CLEARTIMEOUTVIP_REQ	0x00110D0E

class CClearTimeoutVipReq: public IMsgBody
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
		sprintf(buf + offset,
				"{this is the clear the timeout vip player request msgbody");
		offset = (uint32_t) strlen(buf);
	}
public:
	CClearTimeoutVipReq() {}
	virtual ~CClearTimeoutVipReq() {}
};

class TempVipInfo
{
public:
	RoleID nRoleID;
	int64_t nExpireVipTime;

	TempVipInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		nRoleID = enmInvalidRoleID;
		nExpireVipTime = enmInvalidTimeVal;
	}
};

// response of clearing the timeout glory vip
#define MSGID_DSSS_CLEARTIMEOUTVIP_RESP	0x00120D0E
class CClearTimeoutVipResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < UserCountEveryTime; i++)
		{
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrTempVipInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset,
					arrTempVipInfo[i].nExpireVipTime);
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
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nResultCount);
		if (0 > nRet)
		{
			return nRet;
		}
		for (uint32_t i = 0; i < nResultCount && i < UserCountEveryTime; i++)
		{
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrTempVipInfo[i].nRoleID);
			if (0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset,
					arrTempVipInfo[i].nExpireVipTime);
			if (0 > nRet)
			{
				return nRet;
			}
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{CClearTempVipResp, nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		}
		else
		{
			sprintf(buf + offset, "\nnResultCount=%d\n", nResultCount);
			offset = (uint32_t) strlen(buf);
			for (uint32_t i = 0; i < nResultCount && i < MaxNoticeCount; i++)
			{
				sprintf(buf + offset, "\narrTempVipInfo[%d].nRoleID=%d, \nnExpireVipTime=%ld",
						i, arrTempVipInfo[i].nRoleID, arrTempVipInfo[i].nExpireVipTime);
				offset = (uint32_t) strlen(buf);
			}
			sprintf(buf + offset, "}\n");
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CClearTimeoutVipResp()
	{
		nResult = enmDefault_ErrorCode;
		for (uint32_t i = 0; i < UserCountEveryTime; i++)
		{
			arrTempVipInfo[i].Initialize();
		}
	}
	virtual ~CClearTimeoutVipResp() {}

public:
	int32_t nResult;
	uint32_t nResultCount;
	TempVipInfo arrTempVipInfo[UserCountEveryTime];
};

//周充值金额请求
#define MSGID_SSDS_WEEKSYPPLYMENT_REQ		0x00110D0F
class CGetWeekSupplymentReq: public IMsgBody
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
		nRet = CCodeEngine::Encode(buf, size, offset, nWeekIndex);
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
		nRet = CCodeEngine::Decode(buf, size, offset, nWeekIndex);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset,
				"{this is the get week supplyment info request msgbody: nRoleID=%d, nWeekIndex=%d\n}",
				nRoleID, nWeekIndex);
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetWeekSupplymentReq()
	{
		nRoleID = enmInvalidRoleID;
		nWeekIndex = 0;
	}
	virtual ~CGetWeekSupplymentReq() {}

public:
	RoleID nRoleID;
	uint32_t nWeekIndex;
};

//周充值金额响应
#define MSGID_DSSS_WEEKSYPPLYMENT_RESP		0x00120D0F
class CGetWeekSupplymentResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
		nRet = CCodeEngine::Encode(buf, size, offset, nResult);
		if (0 > nRet)
		{
			return nRet;
		}
		if (0 > nResult)
		{
			return S_OK;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nSupplymentAmount);
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
		if (0 > nResult)
		{
			return S_OK;
		}

		nRet = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if (0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nSupplymentAmount);
		if (0 > nRet)
		{
			return nRet;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,", nResult);
		offset = (uint32_t) strlen(buf);
		if (nResult < 0)
		{
			sprintf(buf + offset, "}");
		} else
		{
			sprintf(buf + offset,
					"{nRoleID=%d, nSupplymentAmount=%d}\n",
					 nRoleID, nSupplymentAmount);
		}
		offset = (uint32_t) strlen(buf);
	}
public:
	CGetWeekSupplymentResp()
	{
		nResult = enmDefault_ErrorCode;
		nRoleID = enmInvalidRoleID;
		nSupplymentAmount = 0;
	}
	virtual ~CGetWeekSupplymentResp() {}

public:
	int32_t nResult;
	RoleID  nRoleID;
	uint32_t nSupplymentAmount;
};

//add your message to map
MESSAGEMAP_DECL_BEGIN(sysinfoserver)
MESSAGEMAP_DECL_MSG(MSGID_SSDS_SYPPLYMENT_REQ, (new CGetSupplymentReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_VIPINFO_REQ, (new CGetVipRoleReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_DEGRADE_REQ, (new CDegradeReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_GROUPDEGRADE_REQ, (new CGroupDegradeReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_RANK_REQ, (new CRankInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_NEWMSG_REQ, (new CNewMessageReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_GETMSGCNT_REQ, (new CGetMessageCountReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_GETNOTICEVER_REQ, (new CGetNoticeVersionReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_GETNOTICE_REQ, (new CGetNoticeReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_CLEARTIMEOUTVIP_REQ, (new CClearTimeoutVipReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_GETMSG_REQ, (new CGetMessageReq()))
MESSAGEMAP_DECL_MSG(MSGID_SSDS_WEEKSYPPLYMENT_REQ, (new CGetWeekSupplymentReq()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_SYPPLYMENT_RESP, (new CGetSupplymentResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_VIPINFO_RESP, (new CGetVipInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_DEGRADE_RESP, (new CDegradeResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_GROUPDEGRADE_RESP, (new CGroupDegradeResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_RANK_RESP, (new CRankInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_NEWMSG_RESP, (new CNewMessageResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_GETMSGCNT_RESP, (new CGetMessageCountResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_GETNOTICEVER_RESP, (new CGetNoticeVersionResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_GETNOTICE_RESP, (new CGetNoticeResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_CLEARTIMEOUTVIP_RESP, (new CClearTimeoutVipResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_WEEKSYPPLYMENT_RESP, (new CGetWeekSupplymentResp()))
MESSAGEMAP_DECL_MSG(MSGID_DSSS_GETMSG_RESP, (new CGetMessageResp()))
MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END
#endif /* SYSINFOSERVER_MESSAGE_DEFINE_H_ */
