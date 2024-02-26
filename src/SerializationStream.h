#pragma once

namespace SKSE {
	class SerializationBuffer: public std::streambuf {
	public:
		SerializationBuffer(SerializationInterface& a_intfc);

	protected:
		virtual int_type underflow() override;
		virtual int_type overflow(int_type ch = traits_type::eof()) override;
		virtual int sync() override;

	private:
		char_type				buffer[4096];
		SerializationInterface&	intfc;
	};

	class ISerializationStream: public std::istream {
	public:
		ISerializationStream(SerializationInterface& a_intfc);

	private:
		SerializationBuffer	buffer;
	};

	class OSerializationStream: public std::ostream {
	public:
		OSerializationStream(SerializationInterface& a_intfc);

	private:
		SerializationBuffer	buffer;
	};
}
