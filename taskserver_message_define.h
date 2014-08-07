/*
 * taskserver_message_define.h
 *
 *  Created on: 2012-11-2
 *      Author: liufl
 */

#ifndef TASKSERVER_MESSAGE_DEFINE_H_
#define TASKSERVER_MESSAGE_DEFINE_H_



#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_protocolhead.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"

#include "frame_msg_impl.h"
#include "../lightframe/frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

#define MSGID_DBTASK_GETTASKINFO_REQ    0x00111201
class CGetTaskInfoReq :public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID     nRoleID;
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
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
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nRoleID=%d}\n",
				nRoleID);
	    offset = (uint32_t)strlen(buf);
	}

};

#define MSGID_DBTASK_GETTASKINFO_RESP    0x00121201
class CGetTaskInfoResp :public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetTaskInfoResp()
	{
		nResult = 0;
		nRegisterTime = 0;
		nEmailStat = enmNotCheckType;
		nRoomTime =0;
		nTaskCount = 0;
		nNickNameStat = enmNickName_NoneType;
		nRechargeStat = enmRecharge_NoneType;
		memset(arrTaskID,0,sizeof(arrTaskID));
		memset(arrTaskStat,0,sizeof(arrTaskStat));
	}
public:
	int32_t                       nResult ;
	uint32_t                      nRegisterTime;                   //注册时间
	EmailStat                     nEmailStat;                       //邮箱状态
	uint32_t                      nRoomTime;                        //当天在房间总时间
	NickNameStat                  nNickNameStat;                   // 昵称状态
	RechargeStat                  nRechargeStat;                    //充值状态
	int32_t                       nTaskCount;                       //玩家任务数
	TaskID                        arrTaskID[MAX_TASK_COUNT];        //任务ID号
	TaskStatType                  arrTaskStat[MAX_TASK_COUNT];      //任务状态
	uint32_t                      arrTaskUpdateTime[MAX_TASK_COUNT]; //任务更新时间

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRegisterTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nEmailStat);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoomTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nNickNameStat);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRechargeStat);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTaskCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i =0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrTaskID[i]);
			if (0 > ret)
			{
					return ret;
			}

			ret = CCodeEngine::Encode(buf, size, offset, arrTaskStat[i]);
			if (0 > ret)
			{
					return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrTaskUpdateTime[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRegisterTime);
		if(0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nEmailStat);
		if(0 > ret)
		{
			return ret;
		}

		ret = CCodeEngine::Decode(buf, size, offset, nRoomTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nNickNameStat);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRechargeStat);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTaskCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i =0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrTaskID[i]);
			if (0 > ret)
			{
					return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrTaskStat[i]);
			if (0 > ret)
			{
					return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrTaskUpdateTime[i]);
			if (0 > ret)
			{
					return ret;
			}
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf+offset,"MsgBody={nResult=%d, nTaskCount=%d, nRegisterTime=%d, nEmailStat=%d, nRoomTime=%d, "
				"nNickNameStat = %u ,  nRechargeStat = %u,",
				nResult,nTaskCount, nRegisterTime, nEmailStat, nRoomTime, nNickNameStat, nRechargeStat);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0 ;i < nTaskCount; ++i)
		{
			sprintf(buf + offset, "{nTaskID=%d,nTaskStat=%d,nTaskUpdateTime = %d} ",
					arrTaskID[i],arrTaskStat[i], arrTaskUpdateTime[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf+offset," }\n");
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_DBTASK_UPDATETASKSTAT_NOTIFY  0x00131201
class CUpdateTaskStat :public IMsgBody
{
	SIZE_INTERFACE();
public:
	CUpdateTaskStat()
	{
		nRoleID = 0;
		nTaskCount = 0;
		memset(arrTaskID, 0, sizeof(arrTaskID));
		memset(arrTaskStat, 0, sizeof(arrTaskStat));
	}
public:
	RoleID                nRoleID;
	int32_t               nTaskCount;
	TaskID                arrTaskID[MAX_TASK_COUNT];
	TaskStatType          arrTaskStat[MAX_TASK_COUNT];

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTaskCount);
		if(0 > ret)
		{
			return ret;
		}
		for (int32_t i = 0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrTaskID[ i ]);
			if(0 > ret)
			{
				return ret;
			}
		}
		for (int32_t i = 0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrTaskStat[ i ]);
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

		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTaskCount);
		if(0 > ret)
		{
			return ret;
		}
		for (int32_t i = 0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrTaskID[ i ]);
			if(0 > ret)
			{
				return ret;
			}
		}
		for (int32_t i = 0; i < nTaskCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrTaskStat[ i ]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf+offset,"MsgBody={ nRoleID=%d, nTaskCount=%d ",nRoleID,nTaskCount);
		offset = (uint32_t)strlen(buf);
		for(int32_t i = 0 ; i < nTaskCount; ++i)
		{
			sprintf(buf + offset, "{nTaskID = %d, nTaskStat = %d} ",arrTaskID[ i ], arrTaskStat[ i ]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf+offset, " }");
		offset = (uint32_t)strlen(buf);

	}
};



#define MSGID_TOTASK_ACTION_NOTIFY        0x00131202
class CPlayerActionInfoNoti :public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID			  nRoleID;
	int32_t           nCount;
	ActionID          arrActionID[MAX_ACTION_COUNT];        //行为号
	int32_t           arrOpObject[MAX_ACTION_COUNT];       //操作对象
	int32_t           arrActionNum[MAX_ACTION_COUNT];       //行为数值参数
public:
	CPlayerActionInfoNoti()
	{
		nRoleID = enmInvalidRoleID;
		nCount = 0;
		memset(arrActionID, 0, sizeof(arrActionID));
		memset(arrOpObject, 0, sizeof(arrOpObject));
		memset(arrActionNum, 0, sizeof(arrActionNum));
	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i = 0; i < nCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrActionID[i]);
			if(0 > ret)
			{
				return ret;
			}

			ret = CCodeEngine::Encode(buf, size, offset, arrOpObject[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrActionNum[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for( int32_t i = 0;i < nCount ;++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrActionID[ i ]);
			if(0 > ret)
			{
				return ret;
			}

			ret = CCodeEngine::Decode(buf, size, offset, arrOpObject[ i ]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrActionNum[ i ]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;

	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf+offset,"MsgBody={nRoleID=%d,nCount=%d, ",nRoleID,nCount);
		offset = (uint32_t)strlen(buf);
		for (int32_t i = 0; i < nCount ;++i)
		{
			sprintf(buf+offset,"{arrActionID=%d, arrOpObject=%d, arrActionNum=%d", arrActionID[i],arrOpObject[i], arrActionNum[i]);
			offset = (uint32_t)strlen(buf);
		}
		sprintf(buf+offset, " }");
		offset = (uint32_t)strlen(buf);
	}

};

#define MSGID_TODB_UPDATEASSET_REQ       0x00111203
class CTaskUpdateAssetReq: public IMsgBody
{
	SIZE_INTERFACE();
public:

	CString<enmMaxSerialNumberLength>	strTransID;
	RoleID         nRoleID;
	UpdateAssetOperate  nUpdateMode;            //更新模式：增加或者减少, 1增加，2减少
	uint32_t         nMoney;
	CTaskUpdateAssetReq()
	{
		strTransID = "";
		nRoleID = 0;
		nUpdateMode = enmInvalidUpdateAssetOperate;
		nMoney = 0;
	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = strTransID.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
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
		ret = CCodeEngine::Encode(buf, size, offset, nMoney);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = strTransID.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
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
		ret = CCodeEngine::Decode(buf, size, offset, nMoney);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf+offset,"MsgBody={strTransID=%s,nRoleID=%d, nUpdateMode=%d, nMoney=%d}",strTransID.GetString(),nRoleID,nUpdateMode,nMoney);
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_TODB_UPDATEASSET_RESP      0x00121203
class CTaskUpdateAssetResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t                   nResult;
	CTaskUpdateAssetResp()
	{
		nResult = S_OK;
	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
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
		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf+offset,"MsgBody={nResult=%d }",nResult);
		offset = (uint32_t)strlen(buf);
	}

};

MESSAGEMAP_DECL_BEGIN(taskserver)
MESSAGEMAP_DECL_MSG(MSGID_DBTASK_GETTASKINFO_REQ, (new CGetTaskInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_DBTASK_GETTASKINFO_RESP, (new CGetTaskInfoResp()))
MESSAGEMAP_DECL_MSG(MSGID_DBTASK_UPDATETASKSTAT_NOTIFY, (new CUpdateTaskStat()))
MESSAGEMAP_DECL_MSG(MSGID_TOTASK_ACTION_NOTIFY, (new CPlayerActionInfoNoti()))
MESSAGEMAP_DECL_MSG(MSGID_TODB_UPDATEASSET_REQ, (new CTaskUpdateAssetReq()))
MESSAGEMAP_DECL_MSG(MSGID_TODB_UPDATEASSET_RESP, (new CTaskUpdateAssetResp()))
MESSAGEMAP_DECL_END()



FRAME_NAMESPACE_END


#endif /* TASKSERVER_MESSAGE_DEFINE_H_ */

