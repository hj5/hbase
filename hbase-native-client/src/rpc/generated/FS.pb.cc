// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FS.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "FS.pb.h"

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

const ::google::protobuf::Descriptor* HBaseVersionFileContent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HBaseVersionFileContent_reflection_ = NULL;
const ::google::protobuf::Descriptor* Reference_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Reference_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Reference_Range_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_FS_2eproto() {
  protobuf_AddDesc_FS_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "FS.proto");
  GOOGLE_CHECK(file != NULL);
  HBaseVersionFileContent_descriptor_ = file->message_type(0);
  static const int HBaseVersionFileContent_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HBaseVersionFileContent, version_),
  };
  HBaseVersionFileContent_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HBaseVersionFileContent_descriptor_,
      HBaseVersionFileContent::default_instance_,
      HBaseVersionFileContent_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HBaseVersionFileContent, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HBaseVersionFileContent, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HBaseVersionFileContent));
  Reference_descriptor_ = file->message_type(1);
  static const int Reference_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Reference, splitkey_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Reference, range_),
  };
  Reference_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Reference_descriptor_,
      Reference::default_instance_,
      Reference_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Reference, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Reference, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Reference));
  Reference_Range_descriptor_ = Reference_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_FS_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HBaseVersionFileContent_descriptor_, &HBaseVersionFileContent::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Reference_descriptor_, &Reference::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_FS_2eproto() {
  delete HBaseVersionFileContent::default_instance_;
  delete HBaseVersionFileContent_reflection_;
  delete Reference::default_instance_;
  delete Reference_reflection_;
}

void protobuf_AddDesc_FS_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\010FS.proto\022\010hbase.pb\"*\n\027HBaseVersionFile"
    "Content\022\017\n\007version\030\001 \002(\t\"e\n\tReference\022\020\n"
    "\010splitkey\030\001 \002(\014\022(\n\005range\030\002 \002(\0162\031.hbase.p"
    "b.Reference.Range\"\034\n\005Range\022\007\n\003TOP\020\000\022\n\n\006B"
    "OTTOM\020\001B;\n*org.apache.hadoop.hbase.proto"
    "buf.generatedB\010FSProtosH\001\240\001\001", 228);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "FS.proto", &protobuf_RegisterTypes);
  HBaseVersionFileContent::default_instance_ = new HBaseVersionFileContent();
  Reference::default_instance_ = new Reference();
  HBaseVersionFileContent::default_instance_->InitAsDefaultInstance();
  Reference::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_FS_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_FS_2eproto {
  StaticDescriptorInitializer_FS_2eproto() {
    protobuf_AddDesc_FS_2eproto();
  }
} static_descriptor_initializer_FS_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HBaseVersionFileContent::kVersionFieldNumber;
#endif  // !_MSC_VER

HBaseVersionFileContent::HBaseVersionFileContent()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HBaseVersionFileContent::InitAsDefaultInstance() {
}

HBaseVersionFileContent::HBaseVersionFileContent(const HBaseVersionFileContent& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HBaseVersionFileContent::SharedCtor() {
  _cached_size_ = 0;
  version_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HBaseVersionFileContent::~HBaseVersionFileContent() {
  SharedDtor();
}

void HBaseVersionFileContent::SharedDtor() {
  if (version_ != &::google::protobuf::internal::kEmptyString) {
    delete version_;
  }
  if (this != default_instance_) {
  }
}

void HBaseVersionFileContent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HBaseVersionFileContent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HBaseVersionFileContent_descriptor_;
}

const HBaseVersionFileContent& HBaseVersionFileContent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FS_2eproto();
  return *default_instance_;
}

HBaseVersionFileContent* HBaseVersionFileContent::default_instance_ = NULL;

HBaseVersionFileContent* HBaseVersionFileContent::New() const {
  return new HBaseVersionFileContent;
}

void HBaseVersionFileContent::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_version()) {
      if (version_ != &::google::protobuf::internal::kEmptyString) {
        version_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HBaseVersionFileContent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string version = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_version()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->version().data(), this->version().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void HBaseVersionFileContent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->version(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HBaseVersionFileContent::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->version().data(), this->version().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->version(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HBaseVersionFileContent::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->version());
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

void HBaseVersionFileContent::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HBaseVersionFileContent* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HBaseVersionFileContent*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HBaseVersionFileContent::MergeFrom(const HBaseVersionFileContent& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_version()) {
      set_version(from.version());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HBaseVersionFileContent::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HBaseVersionFileContent::CopyFrom(const HBaseVersionFileContent& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HBaseVersionFileContent::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void HBaseVersionFileContent::Swap(HBaseVersionFileContent* other) {
  if (other != this) {
    std::swap(version_, other->version_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HBaseVersionFileContent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HBaseVersionFileContent_descriptor_;
  metadata.reflection = HBaseVersionFileContent_reflection_;
  return metadata;
}


// ===================================================================

const ::google::protobuf::EnumDescriptor* Reference_Range_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Reference_Range_descriptor_;
}
bool Reference_Range_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Reference_Range Reference::TOP;
const Reference_Range Reference::BOTTOM;
const Reference_Range Reference::Range_MIN;
const Reference_Range Reference::Range_MAX;
const int Reference::Range_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Reference::kSplitkeyFieldNumber;
const int Reference::kRangeFieldNumber;
#endif  // !_MSC_VER

Reference::Reference()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Reference::InitAsDefaultInstance() {
}

Reference::Reference(const Reference& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Reference::SharedCtor() {
  _cached_size_ = 0;
  splitkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  range_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Reference::~Reference() {
  SharedDtor();
}

void Reference::SharedDtor() {
  if (splitkey_ != &::google::protobuf::internal::kEmptyString) {
    delete splitkey_;
  }
  if (this != default_instance_) {
  }
}

void Reference::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Reference::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Reference_descriptor_;
}

const Reference& Reference::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FS_2eproto();
  return *default_instance_;
}

Reference* Reference::default_instance_ = NULL;

Reference* Reference::New() const {
  return new Reference;
}

void Reference::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_splitkey()) {
      if (splitkey_ != &::google::protobuf::internal::kEmptyString) {
        splitkey_->clear();
      }
    }
    range_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Reference::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes splitkey = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_splitkey()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_range;
        break;
      }

      // required .hbase.pb.Reference.Range range = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_range:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::hbase::pb::Reference_Range_IsValid(value)) {
            set_range(static_cast< ::hbase::pb::Reference_Range >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
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

void Reference::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required bytes splitkey = 1;
  if (has_splitkey()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->splitkey(), output);
  }

  // required .hbase.pb.Reference.Range range = 2;
  if (has_range()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->range(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Reference::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes splitkey = 1;
  if (has_splitkey()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->splitkey(), target);
  }

  // required .hbase.pb.Reference.Range range = 2;
  if (has_range()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->range(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Reference::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes splitkey = 1;
    if (has_splitkey()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->splitkey());
    }

    // required .hbase.pb.Reference.Range range = 2;
    if (has_range()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->range());
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

void Reference::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Reference* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Reference*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Reference::MergeFrom(const Reference& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_splitkey()) {
      set_splitkey(from.splitkey());
    }
    if (from.has_range()) {
      set_range(from.range());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Reference::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Reference::CopyFrom(const Reference& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Reference::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Reference::Swap(Reference* other) {
  if (other != this) {
    std::swap(splitkey_, other->splitkey_);
    std::swap(range_, other->range_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Reference::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Reference_descriptor_;
  metadata.reflection = Reference_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

// @@protoc_insertion_point(global_scope)