#pragma once

#include <memory>
#include <string>

#include "../GenericNetRequest.h"
#include "../GenericNetResponse.h"

class Request_5D : public GenericRequest
{
private:
	std::vector< uint8_t > m_data;

	enum CREATE_REPLY {
		SUCCESS = 0,
		FATAL_ERROR,
		GENERAL_ERROR,
	};
public:
	static std::unique_ptr< Request_5D > Create()
	{
		return std::make_unique< Request_5D >();
	}

	sptr_generic_response ProcessRequest( sptr_socket socket, sptr_byte_stream stream ) override;
	void Deserialize( sptr_byte_stream stream ) override;
};

class Result_5D : public GenericResponse {
private:
	int32_t m_reply;

public:
	Result_5D( GenericRequest *request, int32_t reply );
	ByteBuffer &Serialize();
};