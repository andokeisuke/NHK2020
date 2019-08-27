// Generated by gencpp from file custom_msg/RL.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_MESSAGE_RL_H
#define CUSTOM_MSG_MESSAGE_RL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace custom_msg
{
template <class ContainerAllocator>
struct RL_
{
  typedef RL_<ContainerAllocator> Type;

  RL_()
    : right(0)
    , left(0)  {
    }
  RL_(const ContainerAllocator& _alloc)
    : right(0)
    , left(0)  {
  (void)_alloc;
    }



   typedef int64_t _right_type;
  _right_type right;

   typedef int64_t _left_type;
  _left_type left;





  typedef boost::shared_ptr< ::custom_msg::RL_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg::RL_<ContainerAllocator> const> ConstPtr;

}; // struct RL_

typedef ::custom_msg::RL_<std::allocator<void> > RL;

typedef boost::shared_ptr< ::custom_msg::RL > RLPtr;
typedef boost::shared_ptr< ::custom_msg::RL const> RLConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg::RL_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg::RL_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace custom_msg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'custom_msg': ['/home/ando/zyugyourobokon/src/custom_msg/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg::RL_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg::RL_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::RL_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::RL_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::RL_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::RL_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg::RL_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b18a642f9d124a9e6cb20a01284787da";
  }

  static const char* value(const ::custom_msg::RL_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb18a642f9d124a9eULL;
  static const uint64_t static_value2 = 0x6cb20a01284787daULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg::RL_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg/RL";
  }

  static const char* value(const ::custom_msg::RL_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg::RL_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 right\n\
int64 left\n\
";
  }

  static const char* value(const ::custom_msg::RL_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg::RL_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.right);
      stream.next(m.left);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RL_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg::RL_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg::RL_<ContainerAllocator>& v)
  {
    s << indent << "right: ";
    Printer<int64_t>::stream(s, indent + "  ", v.right);
    s << indent << "left: ";
    Printer<int64_t>::stream(s, indent + "  ", v.left);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_MESSAGE_RL_H
