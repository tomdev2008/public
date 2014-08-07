/*
 * tunnelserver_message_define.h
 *
 *  Created on: 2011-12-6
 *      Author: jimm
 */

#ifndef WEBAGENT_MESSAGE_DEFINE_H_
#define WEBAGENT_MESSAGE_DEFINE_H_

#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_msg_impl.h"
#include "public_typedef.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

#define  MSGID_WSRS_MODIFY_ROBOTCONFIG_NOTI      0x00130B01
class CWebModifyRobotConfigNoti: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID		 	nRoomID;
	uint32_t		nRobotPercent;		//�����˸���/���˸�����100
	uint32_t		nSendPercent;			//���Ͳ����ĸ���
public:
	CWebModifyRobotConfigNoti()
	{
		nRoomID = enmInvalidRoomID;
		nRobotPercent = 0;
		nSendPercent = 0;
	}
	virtual ~CWebModifyRobotConfigNoti(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRobotPercent);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nSendPercent);
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
		ret = CCodeEngine::Decode(buf, size, offset, nRobotPercent);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nSendPercent);
		if (0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nRoomID=%d,nRobotPercent=%d,nSendPercent=%d\n", nRoomID,nRobotPercent,nSendPercent);
		offset = (uint32_t)strlen(buf);
	}
};

//#define MSGID_WSOS_PLAYER_MONEY_CHANGE_NOTICE 0x00130B02
//class CWebPlayerMoneyChangeNotice: public IMsgBody
//{
//public:
//	RoleID  nRoleID;    //���179uin
//	int32_t nMoney;     //�޸ĺ������ʲ���179�ҵ�������
//public:
//	CWebPlayerMoneyChangeNotice()
//	{
//		nRoleID = enmInvalidRoleID;
//		nMoney = 0;
//	}
//	virtual ~CWebPlayerMoneyChangeNotice(){}
//public:
//	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t ret = S_OK;
//		ret  = CCodeEngine::Encode(buf,size, offset, nRoleID);
//		if(0 > ret)
//		{
//			return ret;
//		}
//		ret = CCodeEngine::Encode(buf, size,  offset, nMoney);
//		if(0 > ret)
//		{
//			return ret;
//		}
//		return S_OK;
//	}
//	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
//	{
//		int32_t ret = S_OK;
//		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
//		if(0 > ret)
//		{
//			return ret;
//		}
//		ret = CCodeEngine::Decode(buf, size, offset, nMoney);
//		if(0 > ret)
//		{
//			return ret;
//		}
//		return S_OK;
//	}
//	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
//	{
//		sprintf(buf + offset, "{nRoleID=%d, nMoney=%d}\n", nRoleID, nMoney);
//		offset = (uint32_t)strlen(buf);
//	}
//};

/*
*  ��ӡ������Һ�����֪ͨ�� ���ݲ�������ȷ������ӻ���ɾ��
*/
#define MSGID_WEBRS_EDIT_BLACKLIST_NOTICE   0x00130B03
class CWebRSEditBlackListNotice: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID  nRoomID;    //�����
	RoleID  nRoleID;    //179uin
	EditBlackListType  nEditBlackListType;//�޸�����
public:
	CWebRSEditBlackListNotice()
	{
		nRoomID = enmInvalidRoomID;
		nRoleID = enmInvalidRoleID;
		nEditBlackListType = enmEditBlackListType_Invalid;
	}
	virtual ~CWebRSEditBlackListNotice(){}
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
		ret = CCodeEngine::Encode(buf, size, offset, nEditBlackListType);
		if (0 > ret) {
			return ret;
		}
		return ret;
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
		ret = CCodeEngine::Decode(buf, size, offset, nEditBlackListType);
		if (0 > ret) {
			return ret;
		}
		return ret;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nRoleID=%d, nEditBlackListType=%d}\n", nRoomID, nRoleID,nEditBlackListType);
		offset = (uint32_t)strlen(buf);
	}
};

/*
*   ��Ӫ��̨��ѯһ������Ƿ����ߵ�����
*/
#define MSGID_GET_ONLINE_STATUS_REQ     0x00110B04
class CGetOnlineStatusReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nPlayerCount;   //��ѯ���û��ĸ���
	int32_t arrRoleID[MaxGetPlayerOnlineStatusNum];   //MaxGetPlayerOnlineStatusNum = 50
public:
	CGetOnlineStatusReq()
	{
		nPlayerCount = 0;
		memset(arrRoleID, 0, sizeof(arrRoleID));
	}
	virtual ~CGetOnlineStatusReq(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nPlayerCount);
		if(0 > ret)
		{
			return ret;
		}
		if(0 >= nPlayerCount)
		{
			return S_OK;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nPlayerCount);
		if(0 > ret)
		{
			return ret;
		}
		if(0 >= nPlayerCount)
		{
			return S_OK;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nPlayerCount=%d,  ", nPlayerCount);
		offset = (uint32_t)strlen(buf);
		if(0 >= nPlayerCount)
		{
			return;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			sprintf(buf + offset, "nRoleID=%d, ", arrRoleID[i]);
			offset = (uint32_t)strlen(buf);
		}
	}
};

/*
*  ��Ӫ��̨��ѯ�û��Ƿ����ߵ���Ӧ
*/
#define MSGID_GET_ONLINE_STATUS_RESP  0x00120B04
class CGetOnlineStatusResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetOnlineStatusResp()
	{
		nResult = S_OK;
		nPlayerCount = 0;
		memset(arrRoleID, 0, sizeof(arrRoleID));
		memset(arrStatus, 0, sizeof(arrStatus));
	}
	virtual ~CGetOnlineStatusResp(){}
public:
	int32_t nResult;     //��ѯ���
	int32_t nPlayerCount;   //��Ҹ���
	RoleID  arrRoleID[MaxGetPlayerOnlineStatusNum];   //���179uin
	int32_t arrStatus[MaxGetPlayerOnlineStatusNum];     //����״̬, 0��ʾ�����ߣ�1��ʾ����
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPlayerCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrStatus[i]);
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
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPlayerCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrStatus[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "nResult=%d,", nResult);
		offset = (uint32_t)strlen(buf);
		if(0 > nResult)
		{
			return;
		}
		sprintf(buf + offset, "nPlayerCount=%d,", nPlayerCount);
		offset = (uint32_t)strlen(buf);
		if(0 == nPlayerCount)
		{
			return;
		}
		for(int32_t i=0; i<nPlayerCount; ++i)
		{
			sprintf(buf + offset, "{nRoleID=%d, nOnlineStatus=%d},", arrRoleID[i], arrStatus[i]);
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);
	}
};

/*
* ��IP ֪ͨ
*/
#define MSGID_WEBOT_LOCK_NOTICE  0x00130B05
class CLockNotice: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nLockCount;                                //������IP�ĸ�����������
	LockType nLockType;                                 //�������ͣ�3�֣�1���˺ţ�2��������3��IP��ַ
	RoleID   arrRoleID[MaxLockCountOnce];               //�������������֮����в���
	CString<MaxLockContentLength>  arrContent[MaxLockCountOnce]; //���������locktype���������Ϊ1�� ������ҵ�UIN�� Ϊ2�� ����IP�� Ϊ3������mac��ַ
	CString<enmMaxDateTimeStringLength> arrStartTime[MaxLockCountOnce];  //������ʼʱ�䣬datetime���ͣ� ��2012-08-08 00:00:00
	CString<enmMaxDateTimeStringLength> arrEndTime[MaxLockCountOnce];    //��������ʱ�䣬datetime���ͣ� ��2012-08-08 00:00:00
	CString<MaxLockIPReasonLength>   arrLockReason[MaxLockCountOnce];    //����ԭ��
public:
	CLockNotice()
	{
		nLockCount = 0;
		nLockType = 0;
		memset(arrRoleID, 0, sizeof(arrRoleID));
		for(int32_t i=0; i<MaxLockCountOnce; ++i)
		{
			arrContent[i].Initialize();
			arrStartTime[i].Initialize();
			arrEndTime[i].Initialize();
			arrLockReason[i].Initialize();
		}
	}
	virtual ~CLockNotice(){}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nLockCount);
		if(0 > ret)
		{
			return ret;
		}
		if(0 == nLockCount)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nLockType);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nLockCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrContent[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrStartTime[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrEndTime[i].MessageEncode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrLockReason[i].MessageEncode(buf, size, offset);
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
		ret = CCodeEngine::Decode(buf, size, offset, nLockCount);
		if(0 > ret)
		{
			return ret;
		}
		if(0 == nLockCount)
		{
			return S_OK;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nLockType);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nLockCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arrRoleID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrContent[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrStartTime[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrEndTime[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
			ret = arrLockReason[i].MessageDecode(buf, size, offset);
			if(0 > ret)
			{
				return ret;
			}
		}

		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nLockCount=%d", nLockCount);
		offset = (uint32_t)strlen(buf);
		if(nLockCount == 0)
		{
			sprintf(buf + offset, "}\n");
			offset = (uint32_t)strlen(buf);
			return;
		}
		sprintf(buf + offset, ", nLockType=%d, ", nLockType);
		offset = (uint32_t)strlen(buf);

		//dumpǰ��� 0 ���� nlockcount-2 ��Ԫ��
		for(int32_t i=0; i<nLockCount - 1; ++i)
		{
			sprintf(buf + offset, "{arrRoleID[%d]=%d, arrContent[%d]=%s, arrStartTime[%d]=%s, arrEndTime[%d]=%s, arrLockReason[%d]=%s}, ", 
				i, arrRoleID[i], 
				i, arrContent[i].GetString(), 
				i, arrStartTime[i].GetString(), 
				i, arrEndTime[i].GetString(), 
				i, arrLockReason[i].GetString());
			offset = (uint32_t)strlen(buf);
		}

		//dump�� nlockcount - 1 ��Ԫ��
		sprintf(buf + offset, "{arrRoleID[%d]=%d, arrContent[%d]=%s, arrStartTime[%d]=%s, arrEndTime[%d]=%s, arrLockReason[%d]=%s}}\n", 
			nLockCount - 1, arrRoleID[nLockCount - 1], 
			nLockCount - 1, arrContent[nLockCount - 1].GetString(), 
			nLockCount - 1, arrStartTime[nLockCount - 1].GetString(),
			nLockCount - 1, arrEndTime[nLockCount - 1].GetString(),
			nLockCount - 1, arrLockReason[nLockCount - 1].GetString());
		offset = (uint32_t)strlen(buf);
	}
};

#define MSGID_WEBOT_EDIT_PRIVATE_NOTICE  0x00130B06
class CWebEditPrivateMic: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoomID nRoomID;				//��ͨ�ķ���
	EditPrivateType nEditPrivateType;
	RoleID nRoleID; 
public:
	CWebEditPrivateMic()
	{
		nRoomID = enmInvalidRoomID;
		nEditPrivateType = enmEditPrivateType_Invalid;
		nRoleID = enmInvalidRoleID;
	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nEditPrivateType);
		if (0 > ret)
		{
			return ret;
		}
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
		ret = CCodeEngine::Decode(buf, size, offset, nRoomID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nEditPrivateType);
		if (0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoomID=%d, nEditPrivateType=%d, nRoleID=%d}\n", 
			nRoomID,nEditPrivateType, nRoleID);
		offset = (uint32_t)strlen(buf);
	}
};
MESSAGEMAP_DECL_BEGIN(webagent)

MESSAGEMAP_DECL_MSG(MSGID_WSRS_MODIFY_ROBOTCONFIG_NOTI, (new CWebModifyRobotConfigNoti()))
MESSAGEMAP_DECL_MSG(MSGID_WEBRS_EDIT_BLACKLIST_NOTICE, (new CWebRSEditBlackListNotice()))
MESSAGEMAP_DECL_MSG(MSGID_GET_ONLINE_STATUS_REQ, (new CGetOnlineStatusReq()))
MESSAGEMAP_DECL_MSG(MSGID_GET_ONLINE_STATUS_RESP, (new CGetOnlineStatusResp()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_LOCK_NOTICE, (new CLockNotice()))
MESSAGEMAP_DECL_MSG(MSGID_WEBOT_EDIT_PRIVATE_NOTICE, (new CWebEditPrivateMic()))

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END
#endif /* TUNNELSERVER_MESSAGE_DEFINE_H_ */

