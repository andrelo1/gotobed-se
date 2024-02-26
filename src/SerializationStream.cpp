#include "SerializationStream.h"

namespace SKSE {
	SerializationBuffer::SerializationBuffer(SerializationInterface& a_intfc): intfc(a_intfc) {
		setg(buffer, buffer + std::size(buffer), buffer + std::size(buffer));
		setp(buffer, buffer, buffer + std::size(buffer));
	}

	SerializationBuffer::int_type SerializationBuffer::underflow() {
		auto sz = intfc.ReadRecordData(buffer, sizeof(buffer));

		if (!sz) {
			return traits_type::eof();
		}

		setg(buffer, buffer, buffer + sz);

		return traits_type::to_int_type(buffer[0]);
	}

	SerializationBuffer::int_type SerializationBuffer::overflow(int_type ch) {
		if (traits_type::eq_int_type(ch, traits_type::eof())) {
			return traits_type::not_eof(ch);
		}

		if (pptr() < epptr()) {
			*pptr() = traits_type::to_char_type(ch);
			pbump(1);
			return ch;
		}

		if (!intfc.WriteRecordData(buffer, sizeof(buffer))) {
			return traits_type::eof();
		}

		setp(buffer, buffer, buffer + std::size(buffer));
		buffer[0] = traits_type::to_char_type(ch);
		pbump(1);

		return ch;
	}

	int SerializationBuffer::sync() {
		if (!intfc.WriteRecordData(buffer, pptr() - pbase())) {
			return -1;
		}

		setp(buffer, buffer, buffer + std::size(buffer));

		return 0;
	}

	ISerializationStream::ISerializationStream(SerializationInterface& a_intfc): std::istream(&buffer), buffer(a_intfc) {
	}

	OSerializationStream::OSerializationStream(SerializationInterface& a_intfc): std::ostream(&buffer), buffer(a_intfc) {
	}
}
