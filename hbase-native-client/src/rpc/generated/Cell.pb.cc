// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Cell.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Cell.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace hbase {
namespace pb {

namespace {

const ::google::protobuf::Descriptor* Cell_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Cell_reflection_ = NULL;
const ::google::protobuf::Descriptor* KeyValue_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  KeyValue_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* CellType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Cell_2eproto() {
  protobuf_AddDesc_Cell_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Cell.proto");
  GOOGLE_CHECK(file != NULL);
  Cell_descriptor_ = file->message_type(0);
  static const int Cell_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, row_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, family_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, qualifier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, cell_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, tags_),
  };
  Cell_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Cell_descriptor_,
      Cell::default_instance_,
      Cell_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Cell, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Cell));
  KeyValue_descriptor_ = file->message_type(1);
  static const int KeyValue_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, row_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, family_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, qualifier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, key_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, tags_),
  };
  KeyValue_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      KeyValue_descriptor_,
      KeyValue::default_instance_,
      KeyValue_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KeyValue, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(KeyValue));
  CellType_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Cell_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Cell_descriptor_, &Cell::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    KeyValue_descriptor_, &KeyValue::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Cell_2eproto() {
  delete Cell::default_instance_;
  delete Cell_reflection_;
  delete KeyValue::default_instance_;
  delete KeyValue_reflection_;
}

void protobuf_AddDesc_Cell_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nCell.proto\022\010hbase.pb\"\215\001\n\004Cell\022\013\n\003row\030\001"
    " \001(\014\022\016\n\006family\030\002 \001(\014\022\021\n\tqualifier\030\003 \001(\014\022"
    "\021\n\ttimestamp\030\004 \001(\004\022%\n\tcell_type\030\005 \001(\0162\022."
    "hbase.pb.CellType\022\r\n\005value\030\006 \001(\014\022\014\n\004tags"
    "\030\007 \001(\014\"\220\001\n\010KeyValue\022\013\n\003row\030\001 \002(\014\022\016\n\006fami"
    "ly\030\002 \002(\014\022\021\n\tqualifier\030\003 \002(\014\022\021\n\ttimestamp"
    "\030\004 \001(\004\022$\n\010key_type\030\005 \001(\0162\022.hbase.pb.Cell"
    "Type\022\r\n\005value\030\006 \001(\014\022\014\n\004tags\030\007 \001(\014*`\n\010Cel"
    "lType\022\013\n\007MINIMUM\020\000\022\007\n\003PUT\020\004\022\n\n\006DELETE\020\010\022"
    "\021\n\rDELETE_COLUMN\020\014\022\021\n\rDELETE_FAMILY\020\016\022\014\n"
    "\007MAXIMUM\020\377\001B=\n*org.apache.hadoop.hbase.p"
    "rotobuf.generatedB\nCellProtosH\001\240\001\001", 474);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Cell.proto", &protobuf_RegisterTypes);
  Cell::default_instance_ = new Cell();
  KeyValue::default_instance_ = new KeyValue();
  Cell::default_instance_->InitAsDefaultInstance();
  KeyValue::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Cell_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Cell_2eproto {
  StaticDescriptorInitializer_Cell_2eproto() {
    protobuf_AddDesc_Cell_2eproto();
  }
} static_descriptor_initializer_Cell_2eproto_;
const ::google::protobuf::EnumDescriptor* CellType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CellType_descriptor_;
}
bool CellType_IsValid(int value) {
  switch(value) {
    case 0:
    case 4:
    case 8:
    case 12:
    case 14:
    case 255:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int Cell::kRowFieldNumber;
const int Cell::kFamilyFieldNumber;
const int Cell::kQualifierFieldNumber;
const int Cell::kTimestampFieldNumber;
const int Cell::kCellTypeFieldNumber;
const int Cell::kValueFieldNumber;
const int Cell::kTagsFieldNumber;
#endif  // !_MSC_VER

Cell::Cell()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Cell::InitAsDefaultInstance() {
}

Cell::Cell(const Cell& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Cell::SharedCtor() {
  _cached_size_ = 0;
  row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  timestamp_ = GOOGLE_ULONGLONG(0);
  cell_type_ = 0;
  value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Cell::~Cell() {
  SharedDtor();
}

void Cell::SharedDtor() {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    delete row_;
  }
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    delete family_;
  }
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    delete qualifier_;
  }
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    delete tags_;
  }
  if (this != default_instance_) {
  }
}

void Cell::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Cell::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Cell_descriptor_;
}

const Cell& Cell::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Cell_2eproto();
  return *default_instance_;
}

Cell* Cell::default_instance_ = NULL;

Cell* Cell::New() const {
  return new Cell;
}

void Cell::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_row()) {
      if (row_ != &::google::protobuf::internal::kEmptyString) {
        row_->clear();
      }
    }
    if (has_family()) {
      if (family_ != &::google::protobuf::internal::kEmptyString) {
        family_->clear();
      }
    }
    if (has_qualifier()) {
      if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
        qualifier_->clear();
      }
    }
    timestamp_ = GOOGLE_ULONGLONG(0);
    cell_type_ = 0;
    if (has_value()) {
      if (value_ != &::google::protobuf::internal::kEmptyString) {
        value_->clear();
      }
    }
    if (has_tags()) {
      if (tags_ != &::google::protobuf::internal::kEmptyString) {
        tags_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Cell::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes row = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_row()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_family;
        break;
      }

      // optional bytes family = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_family:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_family()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_qualifier;
        break;
      }

      // optional bytes qualifier = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_qualifier:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_qualifier()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_timestamp;
        break;
      }

      // optional uint64 timestamp = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_cell_type;
        break;
      }

      // optional .hbase.pb.CellType cell_type = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_cell_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hbase::pb::CellType_IsValid(value)) {
            set_cell_type(static_cast< ::hbase::pb::CellType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_value;
        break;
      }

      // optional bytes value = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_value()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_tags;
        break;
      }

      // optional bytes tags = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_tags()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Cell::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional bytes row = 1;
  if (has_row()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->row(), output);
  }

  // optional bytes family = 2;
  if (has_family()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->family(), output);
  }

  // optional bytes qualifier = 3;
  if (has_qualifier()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->qualifier(), output);
  }

  // optional uint64 timestamp = 4;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->timestamp(), output);
  }

  // optional .hbase.pb.CellType cell_type = 5;
  if (has_cell_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->cell_type(), output);
  }

  // optional bytes value = 6;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->value(), output);
  }

  // optional bytes tags = 7;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Cell::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional bytes row = 1;
  if (has_row()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->row(), target);
  }

  // optional bytes family = 2;
  if (has_family()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->family(), target);
  }

  // optional bytes qualifier = 3;
  if (has_qualifier()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->qualifier(), target);
  }

  // optional uint64 timestamp = 4;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->timestamp(), target);
  }

  // optional .hbase.pb.CellType cell_type = 5;
  if (has_cell_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->cell_type(), target);
  }

  // optional bytes value = 6;
  if (has_value()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->value(), target);
  }

  // optional bytes tags = 7;
  if (has_tags()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Cell::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bytes row = 1;
    if (has_row()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->row());
    }

    // optional bytes family = 2;
    if (has_family()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->family());
    }

    // optional bytes qualifier = 3;
    if (has_qualifier()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->qualifier());
    }

    // optional uint64 timestamp = 4;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->timestamp());
    }

    // optional .hbase.pb.CellType cell_type = 5;
    if (has_cell_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->cell_type());
    }

    // optional bytes value = 6;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->value());
    }

    // optional bytes tags = 7;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->tags());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Cell::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Cell* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Cell*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Cell::MergeFrom(const Cell& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_row()) {
      set_row(from.row());
    }
    if (from.has_family()) {
      set_family(from.family());
    }
    if (from.has_qualifier()) {
      set_qualifier(from.qualifier());
    }
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_cell_type()) {
      set_cell_type(from.cell_type());
    }
    if (from.has_value()) {
      set_value(from.value());
    }
    if (from.has_tags()) {
      set_tags(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Cell::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Cell::CopyFrom(const Cell& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Cell::IsInitialized() const {

  return true;
}

void Cell::Swap(Cell* other) {
  if (other != this) {
    std::swap(row_, other->row_);
    std::swap(family_, other->family_);
    std::swap(qualifier_, other->qualifier_);
    std::swap(timestamp_, other->timestamp_);
    std::swap(cell_type_, other->cell_type_);
    std::swap(value_, other->value_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Cell::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Cell_descriptor_;
  metadata.reflection = Cell_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int KeyValue::kRowFieldNumber;
const int KeyValue::kFamilyFieldNumber;
const int KeyValue::kQualifierFieldNumber;
const int KeyValue::kTimestampFieldNumber;
const int KeyValue::kKeyTypeFieldNumber;
const int KeyValue::kValueFieldNumber;
const int KeyValue::kTagsFieldNumber;
#endif  // !_MSC_VER

KeyValue::KeyValue()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void KeyValue::InitAsDefaultInstance() {
}

KeyValue::KeyValue(const KeyValue& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void KeyValue::SharedCtor() {
  _cached_size_ = 0;
  row_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  family_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  qualifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  timestamp_ = GOOGLE_ULONGLONG(0);
  key_type_ = 0;
  value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  tags_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

KeyValue::~KeyValue() {
  SharedDtor();
}

void KeyValue::SharedDtor() {
  if (row_ != &::google::protobuf::internal::kEmptyString) {
    delete row_;
  }
  if (family_ != &::google::protobuf::internal::kEmptyString) {
    delete family_;
  }
  if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
    delete qualifier_;
  }
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    delete value_;
  }
  if (tags_ != &::google::protobuf::internal::kEmptyString) {
    delete tags_;
  }
  if (this != default_instance_) {
  }
}

void KeyValue::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* KeyValue::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return KeyValue_descriptor_;
}

const KeyValue& KeyValue::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Cell_2eproto();
  return *default_instance_;
}

KeyValue* KeyValue::default_instance_ = NULL;

KeyValue* KeyValue::New() const {
  return new KeyValue;
}

void KeyValue::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_row()) {
      if (row_ != &::google::protobuf::internal::kEmptyString) {
        row_->clear();
      }
    }
    if (has_family()) {
      if (family_ != &::google::protobuf::internal::kEmptyString) {
        family_->clear();
      }
    }
    if (has_qualifier()) {
      if (qualifier_ != &::google::protobuf::internal::kEmptyString) {
        qualifier_->clear();
      }
    }
    timestamp_ = GOOGLE_ULONGLONG(0);
    key_type_ = 0;
    if (has_value()) {
      if (value_ != &::google::protobuf::internal::kEmptyString) {
        value_->clear();
      }
    }
    if (has_tags()) {
      if (tags_ != &::google::protobuf::internal::kEmptyString) {
        tags_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool KeyValue::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes row = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_row()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_family;
        break;
      }

      // required bytes family = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_family:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_family()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_qualifier;
        break;
      }

      // required bytes qualifier = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_qualifier:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_qualifier()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_timestamp;
        break;
      }

      // optional uint64 timestamp = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_key_type;
        break;
      }

      // optional .hbase.pb.CellType key_type = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_key_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hbase::pb::CellType_IsValid(value)) {
            set_key_type(static_cast< ::hbase::pb::CellType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_value;
        break;
      }

      // optional bytes value = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_value()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_tags;
        break;
      }

      // optional bytes tags = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tags:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_tags()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void KeyValue::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required bytes row = 1;
  if (has_row()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->row(), output);
  }

  // required bytes family = 2;
  if (has_family()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->family(), output);
  }

  // required bytes qualifier = 3;
  if (has_qualifier()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->qualifier(), output);
  }

  // optional uint64 timestamp = 4;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->timestamp(), output);
  }

  // optional .hbase.pb.CellType key_type = 5;
  if (has_key_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->key_type(), output);
  }

  // optional bytes value = 6;
  if (has_value()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->value(), output);
  }

  // optional bytes tags = 7;
  if (has_tags()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->tags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* KeyValue::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes row = 1;
  if (has_row()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->row(), target);
  }

  // required bytes family = 2;
  if (has_family()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->family(), target);
  }

  // required bytes qualifier = 3;
  if (has_qualifier()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->qualifier(), target);
  }

  // optional uint64 timestamp = 4;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->timestamp(), target);
  }

  // optional .hbase.pb.CellType key_type = 5;
  if (has_key_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->key_type(), target);
  }

  // optional bytes value = 6;
  if (has_value()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->value(), target);
  }

  // optional bytes tags = 7;
  if (has_tags()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->tags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int KeyValue::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes row = 1;
    if (has_row()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->row());
    }

    // required bytes family = 2;
    if (has_family()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->family());
    }

    // required bytes qualifier = 3;
    if (has_qualifier()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->qualifier());
    }

    // optional uint64 timestamp = 4;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->timestamp());
    }

    // optional .hbase.pb.CellType key_type = 5;
    if (has_key_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->key_type());
    }

    // optional bytes value = 6;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->value());
    }

    // optional bytes tags = 7;
    if (has_tags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->tags());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void KeyValue::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const KeyValue* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const KeyValue*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void KeyValue::MergeFrom(const KeyValue& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_row()) {
      set_row(from.row());
    }
    if (from.has_family()) {
      set_family(from.family());
    }
    if (from.has_qualifier()) {
      set_qualifier(from.qualifier());
    }
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_key_type()) {
      set_key_type(from.key_type());
    }
    if (from.has_value()) {
      set_value(from.value());
    }
    if (from.has_tags()) {
      set_tags(from.tags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void KeyValue::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void KeyValue::CopyFrom(const KeyValue& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool KeyValue::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void KeyValue::Swap(KeyValue* other) {
  if (other != this) {
    std::swap(row_, other->row_);
    std::swap(family_, other->family_);
    std::swap(qualifier_, other->qualifier_);
    std::swap(timestamp_, other->timestamp_);
    std::swap(key_type_, other->key_type_);
    std::swap(value_, other->value_);
    std::swap(tags_, other->tags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata KeyValue::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = KeyValue_descriptor_;
  metadata.reflection = KeyValue_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

// @@protoc_insertion_point(global_scope)
