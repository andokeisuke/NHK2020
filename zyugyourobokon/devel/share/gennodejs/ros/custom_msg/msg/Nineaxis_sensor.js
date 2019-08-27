// Auto-generated. Do not edit!

// (in-package custom_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class Nineaxis_sensor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.accl = null;
      this.gyro = null;
      this.mag = null;
    }
    else {
      if (initObj.hasOwnProperty('accl')) {
        this.accl = initObj.accl
      }
      else {
        this.accl = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('gyro')) {
        this.gyro = initObj.gyro
      }
      else {
        this.gyro = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('mag')) {
        this.mag = initObj.mag
      }
      else {
        this.mag = new geometry_msgs.msg.Vector3();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Nineaxis_sensor
    // Serialize message field [accl]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.accl, buffer, bufferOffset);
    // Serialize message field [gyro]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.gyro, buffer, bufferOffset);
    // Serialize message field [mag]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.mag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Nineaxis_sensor
    let len;
    let data = new Nineaxis_sensor(null);
    // Deserialize message field [accl]
    data.accl = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [gyro]
    data.gyro = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [mag]
    data.mag = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/Nineaxis_sensor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f88f64117d491e110b918a22793ff2a1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Vector3 accl
    geometry_msgs/Vector3 gyro
    geometry_msgs/Vector3 mag
    
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Nineaxis_sensor(null);
    if (msg.accl !== undefined) {
      resolved.accl = geometry_msgs.msg.Vector3.Resolve(msg.accl)
    }
    else {
      resolved.accl = new geometry_msgs.msg.Vector3()
    }

    if (msg.gyro !== undefined) {
      resolved.gyro = geometry_msgs.msg.Vector3.Resolve(msg.gyro)
    }
    else {
      resolved.gyro = new geometry_msgs.msg.Vector3()
    }

    if (msg.mag !== undefined) {
      resolved.mag = geometry_msgs.msg.Vector3.Resolve(msg.mag)
    }
    else {
      resolved.mag = new geometry_msgs.msg.Vector3()
    }

    return resolved;
    }
};

module.exports = Nineaxis_sensor;
