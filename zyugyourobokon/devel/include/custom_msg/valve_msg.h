// Generated by gencpp from file custom_msg/valve_msg.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_MESSAGE_VALVE_MSG_H
#define CUSTOM_MSG_MESSAGE_VALVE_MSG_H


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
struct valve_msg_
{
  typedef valve_msg_<ContainerAllocator> Type;

  valve_msg_()
    : state(false)
    , valve_number(0)  {
    }
  valve_msg_(const ContainerAllocator& _alloc)
    : state(false)
    , valve_number(0)  {
  (void)_alloc;
    }



   typedef uint8_t _state_type;
  _state_type state;

   typedef int8_t _valve_number_type;
  _valve_number_type valve_number;





  typedef boost::shared_ptr< ::custom_msg::valve_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg::valve_msg_<ContainerAllocator> const> ConstPtr;

}; // struct valve_msg_

typedef ::custom_msg::valve_msg_<std::allocator<void> > valve_msg;

typedef boost::shared_ptr< ::custom_msg::valve_msg > valve_msgPtr;
typedef boost::shared_ptr< ::custom_msg::valve_msg const> valve_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg::valve_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg::valve_msg_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::custom_msg::valve_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg::valve_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::valve_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::valve_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::valve_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::valve_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg::valve_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f60ba44565f980103448a6708624440b";
  }

  static const char* value(const ::custom_msg::valve_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf60ba44565f98010ULL;
  static const uint64_t static_value2 = 0x3448a6708624440bULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg::valve_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg/valve_msg";
  }

  static const char* value(const ::custom_msg::valve_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg::valve_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool state\n\
int8 valve_number\n\
";
  }

  static const char* value(const ::custom_msg::valve_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg::valve_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
      stream.next(m.valve_number);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct valve_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg::valve_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg::valve_msg_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
    s << indent << "valve_number: ";
    Printer<int8_t>::stream(s, indent + "  ", v.valve_number);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_MESSAGE_VALVE_MSG_H
