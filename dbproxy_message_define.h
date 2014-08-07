/*
 * dbproxy_message_define.h
 *
 *  Created on: 2012-3-7
 *      Author: jimm
 */

#ifndef DBPROXY_MESSAGE_DEFINE_H_
#define DBPROXY_MESSAGE_DEFINE_H_


#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_msg_impl.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

#define MSGID_DBAS_REGACCOUNT_REQ					0x00110901
class CRegAccountReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRegAccountReq()
	{
		nAccountType = 0;
		nFromIP = 0;
		nUin = enmInvalidRoleID;
		nConnIndex = 0;
		nEntityType = enmInvalidEntityType;
		nServerID = 0;
	}

	virtual ~CRegAccountReq()
	{

	}

	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
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
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEntityType);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nServerID);
		if(0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t nRet = S_OK;
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
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEntityType);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nServerID);
		if(0 > nRet)
		{
			return nRet;
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nAccountType=%d,nFromIP=%s,nUin=%d, nConnIndex=%d, entityType=%d, ServerID=%d}", nAccountType, inet_ntoa_f(nFromIP), nUin, nConnIndex, nEntityType, nServerID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	AccountType					nAccountType;		//�û����ͣ�����������
	uint32_t					nFromIP;			//��ԴIP�����û���IP
	int32_t						nUin;				//��Դ�ص�uin
	ConnIndex                   nConnIndex;         //���Ӻ�
	EntityType                  nEntityType;        //ʵ������
	ServerID                    nServerID;          //serverid
};

#define MSGID_ASDB_REGACCOUNT_RESP					0x00120901
class CRegAccountResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRegAccountResp()
	{
		nResult = 0;
		nRoleID = enmInvalidRoleID;
		n179ID = 0;
		nExtAccountType = 0;
		nExtUin = 0;
		nConnIndex = 0;
		nEntityType = enmInvalidEntityType;
		nServerID = 0;
	}

	virtual ~CRegAccountResp()
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
		nRet = CCodeEngine::Encode(buf, size, offset, nConnIndex);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nEntityType);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Encode(buf, size, offset, nServerID);
		if(0 > nRet)
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
			nRet = CCodeEngine::Encode(buf, size, offset, n179ID);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nExtAccountType);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Encode(buf, size, offset, nExtUin);
			if(0 > nRet)
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
		nRet = CCodeEngine::Decode(buf, size, offset, nConnIndex);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nEntityType);
		if(0 > nRet)
		{
			return nRet;
		}
		nRet = CCodeEngine::Decode(buf, size, offset, nServerID);
		if(0 > nRet)
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
			nRet = CCodeEngine::Decode(buf, size, offset, n179ID);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nExtAccountType);
			if(0 > nRet)
			{
				return nRet;
			}
			nRet = CCodeEngine::Decode(buf, size, offset, nExtUin);
			if(0 > nRet)
			{
				return nRet;
			}
		}

		return S_OK;
	}

	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d,nConnIndex=%d, entityType=%d, serverid=%d", nResult, nConnIndex, nEntityType, nServerID);
	    offset = (uint32_t)strlen(buf);
	    if(nResult == S_OK)
	    {
	    	sprintf(buf + offset, "nRoleID=%d, n179id=%d, nExtAccountType=%d, nExtUin=%d}", nRoleID, n179ID, nExtAccountType, nExtUin);
	    }
	    else
	    {
	    	sprintf(buf + offset, "}");
	    }
	    offset = (uint32_t)strlen(buf);
	}
public:
	int32_t					nResult;   
	RoleID					nRoleID;         //179uin
	int32_t                 n179ID;          //179�����˺�
	AccountType             nExtAccountType; //�ⲿ�˺����ͣ���51�� qq��
	int32_t                 nExtUin;         //�ⲿ�˺�uin������ⲿ�˺�����Ϊ51�˺ţ�����ֶξ���51uin
	ConnIndex               nConnIndex;      //���Ӻ�
	EntityType              nEntityType; 
	ServerID                nServerID;     
};


MESSAGEMAP_DECL_BEGIN(dbproxyserver)

MESSAGEMAP_DECL_MSG(MSGID_DBAS_REGACCOUNT_REQ, (new CRegAccountReq()))
MESSAGEMAP_DECL_MSG(MSGID_ASDB_REGACCOUNT_RESP, (new CRegAccountResp()))

MESSAGEMAP_DECL_END()



FRAME_NAMESPACE_END

#endif /* DBPROXY_MESSAGE_DEFINE_H_ */
