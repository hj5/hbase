// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: HFile.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "HFile.pb.h"

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

const ::google::protobuf::Descriptor* FileInfoProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FileInfoProto_reflection_ = NULL;
const ::google::protobuf::Descriptor* FileTrailerProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FileTrailerProto_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_HFile_2eproto() {
  protobuf_AddDesc_HFile_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "HFile.proto");
  GOOGLE_CHECK(file != NULL);
  FileInfoProto_descriptor_ = file->message_type(0);
  static const int FileInfoProto_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileInfoProto, map_entry_),
  };
  FileInfoProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FileInfoProto_descriptor_,
      FileInfoProto::default_instance_,
      FileInfoProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileInfoProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileInfoProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FileInfoProto));
  FileTrailerProto_descriptor_ = file->message_type(1);
  static const int FileTrailerProto_offsets_[13] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, file_info_offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, load_on_open_data_offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, uncompressed_data_index_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, total_uncompressed_bytes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, data_index_count_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, meta_index_count_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, entry_count_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, num_data_index_levels_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, first_data_block_offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, last_data_block_offset_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, comparator_class_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, compression_codec_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, encryption_key_),
  };
  FileTrailerProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FileTrailerProto_descriptor_,
      FileTrailerProto::default_instance_,
      FileTrailerProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FileTrailerProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FileTrailerProto));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_HFile_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FileInfoProto_descriptor_, &FileInfoProto::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FileTrailerProto_descriptor_, &FileTrailerProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_HFile_2eproto() {
  delete FileInfoProto::default_instance_;
  delete FileInfoProto_reflection_;
  delete FileTrailerProto::default_instance_;
  delete FileTrailerProto_reflection_;
}

void protobuf_AddDesc_HFile_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::hbase::pb::protobuf_AddDesc_HBase_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013HFile.proto\022\010hbase.pb\032\013HBase.proto\"<\n\r"
    "FileInfoProto\022+\n\tmap_entry\030\001 \003(\0132\030.hbase"
    ".pb.BytesBytesPair\"\221\003\n\020FileTrailerProto\022"
    "\030\n\020file_info_offset\030\001 \001(\004\022 \n\030load_on_ope"
    "n_data_offset\030\002 \001(\004\022$\n\034uncompressed_data"
    "_index_size\030\003 \001(\004\022 \n\030total_uncompressed_"
    "bytes\030\004 \001(\004\022\030\n\020data_index_count\030\005 \001(\r\022\030\n"
    "\020meta_index_count\030\006 \001(\r\022\023\n\013entry_count\030\007"
    " \001(\004\022\035\n\025num_data_index_levels\030\010 \001(\r\022\037\n\027f"
    "irst_data_block_offset\030\t \001(\004\022\036\n\026last_dat"
    "a_block_offset\030\n \001(\004\022\035\n\025comparator_class"
    "_name\030\013 \001(\t\022\031\n\021compression_codec\030\014 \001(\r\022\026"
    "\n\016encryption_key\030\r \001(\014BA\n*org.apache.had"
    "oop.hbase.protobuf.generatedB\013HFileProto"
    "sH\001\210\001\001\240\001\001", 569);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "HFile.proto", &protobuf_RegisterTypes);
  FileInfoProto::default_instance_ = new FileInfoProto();
  FileTrailerProto::default_instance_ = new FileTrailerProto();
  FileInfoProto::default_instance_->InitAsDefaultInstance();
  FileTrailerProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_HFile_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_HFile_2eproto {
  StaticDescriptorInitializer_HFile_2eproto() {
    protobuf_AddDesc_HFile_2eproto();
  }
} static_descriptor_initializer_HFile_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int FileInfoProto::kMapEntryFieldNumber;
#endif  // !_MSC_VER

FileInfoProto::FileInfoProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FileInfoProto::InitAsDefaultInstance() {
}

FileInfoProto::FileInfoProto(const FileInfoProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FileInfoProto::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FileInfoProto::~FileInfoProto() {
  SharedDtor();
}

void FileInfoProto::SharedDtor() {
  if (this != default_instance_) {
  }
}

void FileInfoProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FileInfoProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FileInfoProto_descriptor_;
}

const FileInfoProto& FileInfoProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_HFile_2eproto();
  return *default_instance_;
}

FileInfoProto* FileInfoProto::default_instance_ = NULL;

FileInfoProto* FileInfoProto::New() const {
  return new FileInfoProto;
}

void FileInfoProto::Clear() {
  map_entry_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FileInfoProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .hbase.pb.BytesBytesPair map_entry = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_map_entry:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_map_entry()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_map_entry;
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

void FileInfoProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .hbase.pb.BytesBytesPair map_entry = 1;
  for (int i = 0; i < this->map_entry_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->map_entry(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FileInfoProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .hbase.pb.BytesBytesPair map_entry = 1;
  for (int i = 0; i < this->map_entry_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->map_entry(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FileInfoProto::ByteSize() const {
  int total_size = 0;

  // repeated .hbase.pb.BytesBytesPair map_entry = 1;
  total_size += 1 * this->map_entry_size();
  for (int i = 0; i < this->map_entry_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->map_entry(i));
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

void FileInfoProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FileInfoProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FileInfoProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FileInfoProto::MergeFrom(const FileInfoProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  map_entry_.MergeFrom(from.map_entry_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FileInfoProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FileInfoProto::CopyFrom(const FileInfoProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FileInfoProto::IsInitialized() const {

  for (int i = 0; i < map_entry_size(); i++) {
    if (!this->map_entry(i).IsInitialized()) return false;
  }
  return true;
}

void FileInfoProto::Swap(FileInfoProto* other) {
  if (other != this) {
    map_entry_.Swap(&other->map_entry_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FileInfoProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FileInfoProto_descriptor_;
  metadata.reflection = FileInfoProto_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int FileTrailerProto::kFileInfoOffsetFieldNumber;
const int FileTrailerProto::kLoadOnOpenDataOffsetFieldNumber;
const int FileTrailerProto::kUncompressedDataIndexSizeFieldNumber;
const int FileTrailerProto::kTotalUncompressedBytesFieldNumber;
const int FileTrailerProto::kDataIndexCountFieldNumber;
const int FileTrailerProto::kMetaIndexCountFieldNumber;
const int FileTrailerProto::kEntryCountFieldNumber;
const int FileTrailerProto::kNumDataIndexLevelsFieldNumber;
const int FileTrailerProto::kFirstDataBlockOffsetFieldNumber;
const int FileTrailerProto::kLastDataBlockOffsetFieldNumber;
const int FileTrailerProto::kComparatorClassNameFieldNumber;
const int FileTrailerProto::kCompressionCodecFieldNumber;
const int FileTrailerProto::kEncryptionKeyFieldNumber;
#endif  // !_MSC_VER

FileTrailerProto::FileTrailerProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FileTrailerProto::InitAsDefaultInstance() {
}

FileTrailerProto::FileTrailerProto(const FileTrailerProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FileTrailerProto::SharedCtor() {
  _cached_size_ = 0;
  file_info_offset_ = GOOGLE_ULONGLONG(0);
  load_on_open_data_offset_ = GOOGLE_ULONGLONG(0);
  uncompressed_data_index_size_ = GOOGLE_ULONGLONG(0);
  total_uncompressed_bytes_ = GOOGLE_ULONGLONG(0);
  data_index_count_ = 0u;
  meta_index_count_ = 0u;
  entry_count_ = GOOGLE_ULONGLONG(0);
  num_data_index_levels_ = 0u;
  first_data_block_offset_ = GOOGLE_ULONGLONG(0);
  last_data_block_offset_ = GOOGLE_ULONGLONG(0);
  comparator_class_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  compression_codec_ = 0u;
  encryption_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FileTrailerProto::~FileTrailerProto() {
  SharedDtor();
}

void FileTrailerProto::SharedDtor() {
  if (comparator_class_name_ != &::google::protobuf::internal::kEmptyString) {
    delete comparator_class_name_;
  }
  if (encryption_key_ != &::google::protobuf::internal::kEmptyString) {
    delete encryption_key_;
  }
  if (this != default_instance_) {
  }
}

void FileTrailerProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FileTrailerProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FileTrailerProto_descriptor_;
}

const FileTrailerProto& FileTrailerProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_HFile_2eproto();
  return *default_instance_;
}

FileTrailerProto* FileTrailerProto::default_instance_ = NULL;

FileTrailerProto* FileTrailerProto::New() const {
  return new FileTrailerProto;
}

void FileTrailerProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    file_info_offset_ = GOOGLE_ULONGLONG(0);
    load_on_open_data_offset_ = GOOGLE_ULONGLONG(0);
    uncompressed_data_index_size_ = GOOGLE_ULONGLONG(0);
    total_uncompressed_bytes_ = GOOGLE_ULONGLONG(0);
    data_index_count_ = 0u;
    meta_index_count_ = 0u;
    entry_count_ = GOOGLE_ULONGLONG(0);
    num_data_index_levels_ = 0u;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    first_data_block_offset_ = GOOGLE_ULONGLONG(0);
    last_data_block_offset_ = GOOGLE_ULONGLONG(0);
    if (has_comparator_class_name()) {
      if (comparator_class_name_ != &::google::protobuf::internal::kEmptyString) {
        comparator_class_name_->clear();
      }
    }
    compression_codec_ = 0u;
    if (has_encryption_key()) {
      if (encryption_key_ != &::google::protobuf::internal::kEmptyString) {
        encryption_key_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FileTrailerProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 file_info_offset = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &file_info_offset_)));
          set_has_file_info_offset();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_load_on_open_data_offset;
        break;
      }

      // optional uint64 load_on_open_data_offset = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_load_on_open_data_offset:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &load_on_open_data_offset_)));
          set_has_load_on_open_data_offset();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_uncompressed_data_index_size;
        break;
      }

      // optional uint64 uncompressed_data_index_size = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_uncompressed_data_index_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &uncompressed_data_index_size_)));
          set_has_uncompressed_data_index_size();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_total_uncompressed_bytes;
        break;
      }

      // optional uint64 total_uncompressed_bytes = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_total_uncompressed_bytes:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &total_uncompressed_bytes_)));
          set_has_total_uncompressed_bytes();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_data_index_count;
        break;
      }

      // optional uint32 data_index_count = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_data_index_count:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &data_index_count_)));
          set_has_data_index_count();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_meta_index_count;
        break;
      }

      // optional uint32 meta_index_count = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_meta_index_count:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &meta_index_count_)));
          set_has_meta_index_count();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_entry_count;
        break;
      }

      // optional uint64 entry_count = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_entry_count:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &entry_count_)));
          set_has_entry_count();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_num_data_index_levels;
        break;
      }

      // optional uint32 num_data_index_levels = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_num_data_index_levels:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &num_data_index_levels_)));
          set_has_num_data_index_levels();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_first_data_block_offset;
        break;
      }

      // optional uint64 first_data_block_offset = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_first_data_block_offset:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &first_data_block_offset_)));
          set_has_first_data_block_offset();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(80)) goto parse_last_data_block_offset;
        break;
      }

      // optional uint64 last_data_block_offset = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_last_data_block_offset:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &last_data_block_offset_)));
          set_has_last_data_block_offset();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(90)) goto parse_comparator_class_name;
        break;
      }

      // optional string comparator_class_name = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_comparator_class_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_comparator_class_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->comparator_class_name().data(), this->comparator_class_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_compression_codec;
        break;
      }

      // optional uint32 compression_codec = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_compression_codec:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &compression_codec_)));
          set_has_compression_codec();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(106)) goto parse_encryption_key;
        break;
      }

      // optional bytes encryption_key = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_encryption_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_encryption_key()));
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

void FileTrailerProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint64 file_info_offset = 1;
  if (has_file_info_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->file_info_offset(), output);
  }

  // optional uint64 load_on_open_data_offset = 2;
  if (has_load_on_open_data_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->load_on_open_data_offset(), output);
  }

  // optional uint64 uncompressed_data_index_size = 3;
  if (has_uncompressed_data_index_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->uncompressed_data_index_size(), output);
  }

  // optional uint64 total_uncompressed_bytes = 4;
  if (has_total_uncompressed_bytes()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->total_uncompressed_bytes(), output);
  }

  // optional uint32 data_index_count = 5;
  if (has_data_index_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->data_index_count(), output);
  }

  // optional uint32 meta_index_count = 6;
  if (has_meta_index_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->meta_index_count(), output);
  }

  // optional uint64 entry_count = 7;
  if (has_entry_count()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(7, this->entry_count(), output);
  }

  // optional uint32 num_data_index_levels = 8;
  if (has_num_data_index_levels()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->num_data_index_levels(), output);
  }

  // optional uint64 first_data_block_offset = 9;
  if (has_first_data_block_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(9, this->first_data_block_offset(), output);
  }

  // optional uint64 last_data_block_offset = 10;
  if (has_last_data_block_offset()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(10, this->last_data_block_offset(), output);
  }

  // optional string comparator_class_name = 11;
  if (has_comparator_class_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->comparator_class_name().data(), this->comparator_class_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      11, this->comparator_class_name(), output);
  }

  // optional uint32 compression_codec = 12;
  if (has_compression_codec()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->compression_codec(), output);
  }

  // optional bytes encryption_key = 13;
  if (has_encryption_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      13, this->encryption_key(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FileTrailerProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional uint64 file_info_offset = 1;
  if (has_file_info_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->file_info_offset(), target);
  }

  // optional uint64 load_on_open_data_offset = 2;
  if (has_load_on_open_data_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->load_on_open_data_offset(), target);
  }

  // optional uint64 uncompressed_data_index_size = 3;
  if (has_uncompressed_data_index_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->uncompressed_data_index_size(), target);
  }

  // optional uint64 total_uncompressed_bytes = 4;
  if (has_total_uncompressed_bytes()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->total_uncompressed_bytes(), target);
  }

  // optional uint32 data_index_count = 5;
  if (has_data_index_count()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->data_index_count(), target);
  }

  // optional uint32 meta_index_count = 6;
  if (has_meta_index_count()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->meta_index_count(), target);
  }

  // optional uint64 entry_count = 7;
  if (has_entry_count()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(7, this->entry_count(), target);
  }

  // optional uint32 num_data_index_levels = 8;
  if (has_num_data_index_levels()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->num_data_index_levels(), target);
  }

  // optional uint64 first_data_block_offset = 9;
  if (has_first_data_block_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(9, this->first_data_block_offset(), target);
  }

  // optional uint64 last_data_block_offset = 10;
  if (has_last_data_block_offset()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(10, this->last_data_block_offset(), target);
  }

  // optional string comparator_class_name = 11;
  if (has_comparator_class_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->comparator_class_name().data(), this->comparator_class_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        11, this->comparator_class_name(), target);
  }

  // optional uint32 compression_codec = 12;
  if (has_compression_codec()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->compression_codec(), target);
  }

  // optional bytes encryption_key = 13;
  if (has_encryption_key()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        13, this->encryption_key(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FileTrailerProto::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint64 file_info_offset = 1;
    if (has_file_info_offset()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->file_info_offset());
    }

    // optional uint64 load_on_open_data_offset = 2;
    if (has_load_on_open_data_offset()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->load_on_open_data_offset());
    }

    // optional uint64 uncompressed_data_index_size = 3;
    if (has_uncompressed_data_index_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->uncompressed_data_index_size());
    }

    // optional uint64 total_uncompressed_bytes = 4;
    if (has_total_uncompressed_bytes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->total_uncompressed_bytes());
    }

    // optional uint32 data_index_count = 5;
    if (has_data_index_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->data_index_count());
    }

    // optional uint32 meta_index_count = 6;
    if (has_meta_index_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->meta_index_count());
    }

    // optional uint64 entry_count = 7;
    if (has_entry_count()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->entry_count());
    }

    // optional uint32 num_data_index_levels = 8;
    if (has_num_data_index_levels()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->num_data_index_levels());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint64 first_data_block_offset = 9;
    if (has_first_data_block_offset()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->first_data_block_offset());
    }

    // optional uint64 last_data_block_offset = 10;
    if (has_last_data_block_offset()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->last_data_block_offset());
    }

    // optional string comparator_class_name = 11;
    if (has_comparator_class_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->comparator_class_name());
    }

    // optional uint32 compression_codec = 12;
    if (has_compression_codec()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->compression_codec());
    }

    // optional bytes encryption_key = 13;
    if (has_encryption_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->encryption_key());
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

void FileTrailerProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FileTrailerProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FileTrailerProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FileTrailerProto::MergeFrom(const FileTrailerProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_file_info_offset()) {
      set_file_info_offset(from.file_info_offset());
    }
    if (from.has_load_on_open_data_offset()) {
      set_load_on_open_data_offset(from.load_on_open_data_offset());
    }
    if (from.has_uncompressed_data_index_size()) {
      set_uncompressed_data_index_size(from.uncompressed_data_index_size());
    }
    if (from.has_total_uncompressed_bytes()) {
      set_total_uncompressed_bytes(from.total_uncompressed_bytes());
    }
    if (from.has_data_index_count()) {
      set_data_index_count(from.data_index_count());
    }
    if (from.has_meta_index_count()) {
      set_meta_index_count(from.meta_index_count());
    }
    if (from.has_entry_count()) {
      set_entry_count(from.entry_count());
    }
    if (from.has_num_data_index_levels()) {
      set_num_data_index_levels(from.num_data_index_levels());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_first_data_block_offset()) {
      set_first_data_block_offset(from.first_data_block_offset());
    }
    if (from.has_last_data_block_offset()) {
      set_last_data_block_offset(from.last_data_block_offset());
    }
    if (from.has_comparator_class_name()) {
      set_comparator_class_name(from.comparator_class_name());
    }
    if (from.has_compression_codec()) {
      set_compression_codec(from.compression_codec());
    }
    if (from.has_encryption_key()) {
      set_encryption_key(from.encryption_key());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FileTrailerProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FileTrailerProto::CopyFrom(const FileTrailerProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FileTrailerProto::IsInitialized() const {

  return true;
}

void FileTrailerProto::Swap(FileTrailerProto* other) {
  if (other != this) {
    std::swap(file_info_offset_, other->file_info_offset_);
    std::swap(load_on_open_data_offset_, other->load_on_open_data_offset_);
    std::swap(uncompressed_data_index_size_, other->uncompressed_data_index_size_);
    std::swap(total_uncompressed_bytes_, other->total_uncompressed_bytes_);
    std::swap(data_index_count_, other->data_index_count_);
    std::swap(meta_index_count_, other->meta_index_count_);
    std::swap(entry_count_, other->entry_count_);
    std::swap(num_data_index_levels_, other->num_data_index_levels_);
    std::swap(first_data_block_offset_, other->first_data_block_offset_);
    std::swap(last_data_block_offset_, other->last_data_block_offset_);
    std::swap(comparator_class_name_, other->comparator_class_name_);
    std::swap(compression_codec_, other->compression_codec_);
    std::swap(encryption_key_, other->encryption_key_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FileTrailerProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FileTrailerProto_descriptor_;
  metadata.reflection = FileTrailerProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb
}  // namespace hbase

// @@protoc_insertion_point(global_scope)
