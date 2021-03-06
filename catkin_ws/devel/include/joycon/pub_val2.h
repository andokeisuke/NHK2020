// Generated by gencpp from file joycon/pub_val2.msg
// DO NOT EDIT!


#ifndef JOYCON_MESSAGE_PUB_VAL2_H
#define JOYCON_MESSAGE_PUB_VAL2_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace joycon
{
template <class ContainerAllocator>
struct pub_val2_
{
  typedef pub_val2_<ContainerAllocator> Type;

  pub_val2_()
    : theta(0)
    , r(0.0)  {
    }
  pub_val2_(const ContainerAllocator& _alloc)
    : theta(0)
    , r(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _theta_type;
  _theta_type theta;

   typedef float _r_type;
  _r_type r;





  typedef boost::shared_ptr< ::joycon::pub_val2_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::joycon::pub_val2_<ContainerAllocator> const> ConstPtr;

}; // struct pub_val2_

typedef ::joycon::pub_val2_<std::allocator<void> > pub_val2;

typedef boost::shared_ptr< ::joycon::pub_val2 > pub_val2Ptr;
typedef boost::shared_ptr< ::joycon::pub_val2 const> pub_val2ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::joycon::pub_val2_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::joycon::pub_val2_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace joycon

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'joycon': ['/home/ando/catkin_ws/src/joycon/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::joycon::pub_val2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::joycon::pub_val2_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::joycon::pub_val2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::joycon::pub_val2_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::joycon::pub_val2_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::joycon::pub_val2_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::joycon::pub_val2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a801c0838fbcc9070f818be3d380d84a";
  }

  static const char* value(const ::joycon::pub_val2_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa801c0838fbcc907ULL;
  static const uint64_t static_value2 = 0x0f818be3d380d84aULL;
};

template<class ContainerAllocator>
struct DataType< ::joycon::pub_val2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "joycon/pub_val2";
  }

  static const char* value(const ::joycon::pub_val2_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::joycon::pub_val2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 theta\n\
float32 r\n\
\n\
";
  }

  static const char* value(const ::joycon::pub_val2_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::joycon::pub_val2_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.theta);
      stream.next(m.r);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pub_val2_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::joycon::pub_val2_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::joycon::pub_val2_<ContainerAllocator>& v)
  {
    s << indent << "theta: ";
    Printer<int32_t>::stream(s, indent + "  ", v.theta);
    s << indent << "r: ";
    Printer<float>::stream(s, indent + "  ", v.r);
  }
};

} // namespace message_operations
} // namespace ros

#endif // JOYCON_MESSAGE_PUB_VAL2_H
