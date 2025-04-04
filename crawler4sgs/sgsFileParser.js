const aesjs = require("./js/aes.js");
const Zlib = require("./js/node-zlib.js");
const fs = require("fs");

class AESUtils {
  constructor() {
    var t = new Uint8Array([
        70, 114, 69, 107, 85, 80, 55, 120, 97, 78, 63, 38, 114, 101, 81, 61,
        106, 69, 102, 114, 97, 116, 104, 101, 119, 53, 101, 71, 53, 81, 69, 99,
      ]),
      e = new Uint8Array([
        115, 101, 66, 55, 36, 70, 53, 83, 35, 117, 102, 97, 109, 85, 109, 65,
      ]),
      n = new Uint8Array([
        115, 101, 66, 55, 36, 70, 53, 83, 35, 117, 102, 97, 109, 85, 109, 65,
      ]);

    this.encryptCounter = new aesjs.Counter(e);
    this.decryptCounter = new aesjs.Counter(n);
    this.encrypt = new aesjs.ModeOfOperation.ctr(t, this.encryptCounter);
    this.decrypt = new aesjs.ModeOfOperation.ctr(t, this.decryptCounter);
    this.jofb = undefined;
  }
  AesEncrypt(t) {
    if (this.encrypt) {
      return this.encrypt.encrypt(new Uint8Array(t));
    }
    return null;
  }
  AesDecrypt(t) {
    if (this.decrypt) {
      return this.decrypt.decrypt(new Uint8Array(t));
    }
    return null;
  }
  InitOfb() {
    var t = [
        20, 51, 69, 107, 85, 94, 55, 120, 97, 78, 63, 45, 114, 101, 81, 61,
      ],
      e = new Float32Array([
        137, 101, 62, 55, 36, 70, 86, 69, 35, 117, 67, 33, 109, 85, 97, 225,
      ]);
    this.jofb = new aesjs.ModeOfOperation.ofb(t, e);
  }
  AesOfb(t) {
    if (this.jofb === undefined || this.jofb === null) {
      this.InitOfb();
    }

    return this.jofb.decrypt(new Uint8Array(t));
  }
}

function parseEncryptedConfigFile(content) {
  var aesUtils = new AESUtils();
  var decryptedFile = aesUtils.AesOfb(content);
  var unzipedFile = Zlib.gunzipSync(decryptedFile);
  var jsonObj = JSON.parse(unzipedFile);

  return jsonObj;
}

function readLocalEncryptedSGS() {
  var encryptedSGSFolder = "./encrypted-sgs";
  var decryptedJSONFolder = "./decrypted-json";

  var files = fs.readdirSync(encryptedSGSFolder);
  files.forEach(function (ele, index) {
    filePath = encryptedSGSFolder + "/" + ele;
    if (fs.statSync(filePath).isDirectory() || !filePath.endsWith(".sgs")) {
      return;
    }

    var buffer = fs.readFileSync(filePath);
    var decryptedJsonObj = parseEncryptedConfigFile(buffer);
    var newFile = decryptedJSONFolder + "/" + ele.replace(".sgs", ".json");

    if (!fs.existsSync(decryptedJSONFolder)) {
      fs.mkdirSync(decryptedJSONFolder);
    }
    fs.writeFile(newFile, JSON.stringify(decryptedJsonObj), function (err) {
      if (err) {
        return console.log(err);
      }

      console.log(newFile + " was saved!");
    });
  });
}

readLocalEncryptedSGS();
