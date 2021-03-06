// Generated by gencpp from file custom_msg/wh_msg.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSG_MESSAGE_WH_MSG_H
#define CUSTOM_MSG_MESSAGE_WH_MSG_H


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
struct wh_msg_
{
  typedef wh_msg_<ContainerAllocator> Type;

  wh_msg_()
    : st_target_deg(0.0)
    , st_now_deg(0.0)
    , wh_target_vel(0.0)
    , wh_now_vel(0.0)  {
    }
  wh_msg_(const ContainerAllocator& _alloc)
    : st_target_deg(0.0)
    , st_now_deg(0.0)
    , wh_target_vel(0.0)
    , wh_now_vel(0.0)  {
  (void)_alloc;
    }



   typedef double _st_target_deg_type;
  _st_target_deg_type st_target_deg;

   typedef double _st_now_deg_type;
  _st_now_deg_type st_now_deg;

   typedef double _wh_target_vel_type;
  _wh_target_vel_type wh_target_vel;

   typedef double _wh_now_vel_type;
  _wh_now_vel_type wh_now_vel;





  typedef boost::shared_ptr< ::custom_msg::wh_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msg::wh_msg_<ContainerAllocator> const> ConstPtr;

}; // struct wh_msg_

typedef ::custom_msg::wh_msg_<std::allocator<void> > wh_msg;

typedef boost::shared_ptr< ::custom_msg::wh_msg > wh_msgPtr;
typedef boost::shared_ptr< ::custom_msg::wh_msg const> wh_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msg::wh_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msg::wh_msg_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::custom_msg::wh_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msg::wh_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::wh_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msg::wh_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::wh_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msg::wh_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msg::wh_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f89faf035737b3c1eab14ea32778c58c";
  }

  static const char* value(const ::custom_msg::wh_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf89faf035737b3c1ULL;
  static const uint64_t static_value2 = 0xeab14ea32778c58cULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msg::wh_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msg/wh_msg";
  }

  static const char* value(const ::custom_msg::wh_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msg::wh_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 st_target_deg\n\
float64 st_now_deg\n\
float64 wh_target_vel\n\
float64 wh_now_vel\n\
";
  }

  static const char* value(const ::custom_msg::wh_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msg::wh_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.st_target_deg);
      stream.next(m.st_now_deg);
      stream.next(m.wh_target_vel);
      stream.next(m.wh_now_vel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct wh_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msg::wh_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msg::wh_msg_<ContainerAllocator>& v)
  {
    s << indent << "st_target_deg: ";
    Printer<double>::stream(s, indent + "  ", v.st_target_deg);
    s << indent << "st_now_deg: ";
    Printer<double>::stream(s, indent + "  ", v.st_now_deg);
    s << indent << "wh_target_vel: ";
    Printer<double>::stream(s, indent + "  ", v.wh_target_vel);
    s << indent << "wh_now_vel: ";
    Printer<double>::stream(s, indent + "  ", v.wh_now_vel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSG_MESSAGE_WH_MSG_H
