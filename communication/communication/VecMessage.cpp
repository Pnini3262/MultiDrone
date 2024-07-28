#include "VecMessage.h"
#include "../Validation/CRCalgoritm.h"
#include "../Validation/Convert.h"

vector<uint8_t> VecMessage::getreminder(int,  vector<uint8_t>& key)
{
    Convert cn;
    vector<uint8_t> vec= cn.convertCharVecToUint8(this->message) ;
    CRCalgoritm crc;

    try {
        return crc.getRemainder(vec, key);
    }catch(runtime_error err){
        throw err;
    }

}

void VecMessage::checkInReceive(vector<uint8_t>& valiDationData, vector<uint8_t>& key)throw (runtime_error)
{
    Convert cn;
    vector<uint8_t> vec = cn.convertCharVecToUint8(this->message);
    CRCalgoritm crc;
    crc.copyArr(valiDationData, vec, valiDationData.size());
    try {
        crc.receiver(vec, key);
    }
    catch (runtime_error error) {
        throw error;
    }
}
