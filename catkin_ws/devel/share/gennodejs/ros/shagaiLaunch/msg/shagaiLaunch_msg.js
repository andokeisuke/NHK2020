// Auto-generated. Do not edit!

// (in-package shagaiLaunch.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class shagaiLaunch_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.phase = null;
      this.action = null;
    }
    else {
      if (initObj.hasOwnProperty('phase')) {
        this.phase = initObj.phase
      }
      else {
        this.phase = 0;
      }
      if (initObj.hasOwnProperty('action')) {
        this.action = initObj.action
      }
      else {
        this.action = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type shagaiLaunch_msg
    // Serialize message field [phase]
    bufferOffset = _serializer.int8(obj.phase, buffer, bufferOffset);
    // Serialize message field [action]
    bufferOffset = _serializer.string(obj.action, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type shagaiLaunch_msg
    let len;
    let data = new shagaiLaunch_msg(null);
    // Deserialize message field [phase]
    data.phase = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [action]
    data.action = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.action.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'shagaiLaunch/shagaiLaunch_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5d4369385089c16dc86085a13d1749a8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 phase
    string action
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new shagaiLaunch_msg(null);
    if (msg.phase !== undefined) {
      resolved.phase = msg.phase;
    }
    else {
      resolved.phase = 0
    }

    if (msg.action !== undefined) {
      resolved.action = msg.action;
    }
    else {
      resolved.action = ''
    }

    return resolved;
    }
};

module.exports = shagaiLaunch_msg;
