#pragma once

namespace {
template <typename PtrType, PtrType PtrValue, typename TagType>
struct private_access {
    friend PtrType get(TagType) { return PtrValue; }
};
}

#define PRIVATE_ACCESS_DETAIL_CONCATENATE_IMPL(x, y) x##y

#define PRIVATE_ACCESS_DETAIL_CONCATENATE(x, y)  \
  PRIVATE_ACCESS_DETAIL_CONCATENATE_IMPL(x, y)

#define PRIVATE_ACCESS_DETAIL_ACCESS_PRIVATE(Tag, Class, Type, Name, PtrTypeKind)  \
  namespace {                                                                      \
    struct Tag {};                                                                 \
    template struct private_access<decltype(&Class::Name), &Class::Name, Tag>;     \
    using PRIVATE_ACCESS_DETAIL_CONCATENATE(Alias_, Tag) = Type;                   \
    using PRIVATE_ACCESS_DETAIL_CONCATENATE(PtrType_, Tag) =                       \
        PRIVATE_ACCESS_DETAIL_CONCATENATE(Alias_, Tag) PtrTypeKind;                \
    PRIVATE_ACCESS_DETAIL_CONCATENATE(PtrType_, Tag) get(Tag);                     \
  }

#define PRIVATE_ACCESS_DETAIL_ACCESS_PRIVATE_FIELD(Tag, Class, Type, Name)     \
  PRIVATE_ACCESS_DETAIL_ACCESS_PRIVATE(Tag, Class, Type, Name, Class::*)       \
  namespace {                                                                  \
    Type & Class##Name(Class &&t) { return t.*get(Tag{}); }                    \
    Type & Class##Name(Class &t) { return t.*get(Tag{}); }                     \
    using PRIVATE_ACCESS_DETAIL_CONCATENATE(X, Tag) = Type;                    \
    using PRIVATE_ACCESS_DETAIL_CONCATENATE(Y, Tag) =                          \
        const PRIVATE_ACCESS_DETAIL_CONCATENATE(X, Tag);                       \
    PRIVATE_ACCESS_DETAIL_CONCATENATE(Y, Tag) & Class##Name(const Class &t) {  \
        return t.*get(Tag{});                                                  \
    }                                                                          \
  }

#define PRIVATE_ACCESS_DETAIL_UNIQUE_TAG                           \
  PRIVATE_ACCESS_DETAIL_CONCATENATE(PrivateAccessTag, __COUNTER__)

#define ACCESS_PRIVATE_FIELD(Class, Type, Name)                                 \
  PRIVATE_ACCESS_DETAIL_ACCESS_PRIVATE_FIELD(PRIVATE_ACCESS_DETAIL_UNIQUE_TAG,  \
                                             Class, Type, Name)