// Auto-generated. Do not edit!

// (in-package custom_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class wh_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.st_target_deg = null;
      this.st_now_deg = null;
      this.wh_target_vel = null;
      this.wh_now_vel = null;
    }
    else {
      if (initObj.hasOwnProperty('st_target_deg')) {
        this.st_target_deg = initObj.st_target_deg
      }
      else {
        this.st_target_deg = 0.0;
      }
      if (initObj.hasOwnProperty('st_now_deg')) {
        this.st_now_deg = initObj.st_now_deg
      }
      else {
        this.st_now_deg = 0.0;
      }
      if (initObj.hasOwnProperty('wh_target_vel')) {
        this.wh_target_vel = initObj.wh_target_vel
      }
      else {
        this.wh_target_vel = 0.0;
      }
      if (initObj.hasOwnProperty('wh_now_vel')) {
        this.wh_now_vel = initObj.wh_now_vel
      }
      else {
        this.wh_now_vel = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type wh_msg
    // Serialize message field [st_target_deg]
    bufferOffset = _serializer.float64(obj.st_target_deg, buffer, bufferOffset);
    // Serialize message field [st_now_deg]
    bufferOffset = _serializer.float64(obj.st_now_deg, buffer, bufferOffset);
    // Serialize message field [wh_target_vel]
    bufferOffset = _serializer.float64(obj.wh_target_vel, buffer, bufferOffset);
    // Serialize message field [wh_now_vel]
    bufferOffset = _serializer.float64(obj.wh_now_vel, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type wh_msg
    let len;
    let data = new wh_msg(null);
    // Deserialize message field [st_target_deg]
    data.st_target_deg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [st_now_deg]
    data.st_now_deg = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [wh_target_vel]
    data.wh_target_vel = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [wh_now_vel]
    data.wh_now_vel = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/wh_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f89faf035737b3c1eab14ea32778c58c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 st_target_deg
    float64 st_now_deg
    float64 wh_target_vel
    float64 wh_now_vel
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new wh_msg(null);
    if (msg.st_target_deg !== undefined) {
      resolved.st_target_deg = msg.st_target_deg;
    }
    else {
      resolved.st_target_deg = 0.0
    }

    if (msg.st_now_deg !== undefined) {
      resolved.st_now_deg = msg.st_now_deg;
    }
    else {
      resolved.st_now_deg = 0.0
    }

    if (msg.wh_target_vel !== undefined) {
      resolved.wh_target_vel = msg.wh_target_vel;
    }
    else {
      resolved.wh_target_vel = 0.0
    }

    if (msg.wh_now_vel !== undefined) {
      resolved.wh_now_vel = msg.wh_now_vel;
    }
    else {
      resolved.wh_now_vel = 0.0
    }

    return resolved;
    }
};

module.exports = wh_msg;
