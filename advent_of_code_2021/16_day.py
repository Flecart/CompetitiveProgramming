import pdb

class Packet():
  def __init__(self, version: int, id: int):
    """
    Informazioni presenti in un singolo pacchetto
    """
    self.version = version
    self.id = id 
    self.data = None

  def add_number(self,val:int):
    self.data = val

  def add_packet(self, packet):
    """
    Puoi aggiungere un pacchetto solamente nel caso non sia un pacchetto terminale
    """
    if(self.data == None):
      self.data = []

    assert(type(self.data) == type(list()))
    assert(self.id != 4)
    self.data.append(packet)
  
  def __repr__(self):
    version = self.version
    id = self.id
    data = self.data
    if self.data==None:
      return f"[ERROR {version=},{id=}]"
    elif self.id == 4:
      return f"[{version=},{id=},{data=}]"
    else:
      out = f"[{version=},{id=} :"
      for node in self.data:
          out += " " + node.__repr__() + " "
      out+= "]"
      return out

  def eval(self):
    def sum_value():
      all_sum = 0
      for packet in self.data:
        all_sum += packet.eval()
      return all_sum

    def product():
      """
      WARNING: returns 1 if no childs
      """
      prod = 1
      for packet in self.data:
        prod *= packet.eval() 

      return prod 

    def min_value():
      from sys import maxsize
      min_value = maxsize
      for packet in self.data:
        min_value = min(min_value, packet.eval())
      return min_value
      
    def max_value():
      from sys import maxsize
      max_value = -maxsize-1
      for packet in self.data:
        max_value = max(max_value, packet.eval())
      return max_value

    def greather_than():
      assert(len(self.data)==2)
      return 1 if self.data[0].eval() > self.data[1].eval() else 0

    def less_than():
      assert(len(self.data)==2)
      return 1 if self.data[0].eval() < self.data[1].eval() else 0


    def equal_to():
      assert(len(self.data)==2)
      return 1 if self.data[0].eval() == self.data[1].eval() else 0
    
    map_eval={
      0:sum_value, 
      1:product,
      2:min_value,
      3:max_value,
      5:greather_than,
      6:less_than,
      7:equal_to
    }
      
    if self.id==4 : 
      return self.data 
    else:
      return map_eval[self.id]()
          
    

def process(binaryString:str):
  
  def _get_version(binary:str)->int:
    return int(binary[:3], 2)

  def _get_id(binary:str)->int:
    return int(binary[3:6], 2) 

  def _get_type(binary: str)->int:
    return int(binary[6])

  
  var: int = _get_version(binaryString)
  id: int  = _get_id(binaryString)
  
  
  packet = Packet(var, id)
  lastIndex: int = 0
  if(id==4):
    lastIndex = 6
    lastBuff = False
    bitOfVal:str = ""
    while not lastBuff:
      currentSub = binaryString[lastIndex:lastIndex+5]
      bitOfVal += currentSub[1:5]
      lastBuff = currentSub[0]=='0'
      lastIndex+=5
    
    val: int = int(bitOfVal,2)
    packet.add_number(val)
  else:
    # pdb.set_trace()
    typeid = _get_type(binaryString) 
    lastIndex = 7
    if typeid == 1:
      # 11: n pacchetti
      n_packets = int(binaryString[lastIndex:lastIndex + 11], 2)
      starting_index = lastIndex + 11
      for i in range(n_packets):
        index, newPacket = process(binaryString[starting_index:])
        starting_index += index 
        packet.add_packet(newPacket)
      lastIndex = starting_index
    elif typeid == 0:
      # 15: lunghezza dei pacchetti
      lenghtBit:int = int(binaryString[lastIndex:lastIndex + 15], 2)
      lastIndex+=15
      beginOfSub:int = lastIndex
      endOfSub:int = lastIndex+lenghtBit
      while (beginOfSub < endOfSub):
        index, newPacket = process(binaryString[beginOfSub:endOfSub])
        packet.add_packet(newPacket)
        beginOfSub += index
      lastIndex = endOfSub

  
  if(packet.data==None):
    pdb.set_trace()
  return (lastIndex,packet)

def first_star(packet):
  from queue import Queue 
  queue = Queue() 
  res = 0
  if packet.id != 4:
    queue.put(packet) 
  else:
    res = packet.version
    
  while not queue.empty():
    curr = queue.get()  
    res += curr.version 
    if curr.id != 4 and curr.data != None:
      for sub_packet in curr.data:
        queue.put(sub_packet)
  return res
  
def second_star(packet):
  return packet.eval()

def solOnFile(file:str) -> int:
  def convertInputToBinaryStr(hex_value: str):
    binary = (bin(int(hex_value,16))[2:]).zfill(len(hex_value)*4)
    binary = str(binary)
    return binary
  
  with open(file,"r") as f:
    code = f.read().strip()

    input = convertInputToBinaryStr(code)

    packetStructure = process(input)[1]
    print(packetStructure)
    res = first_star(packetStructure)
    res2 = second_star(packetStructure)
    return (res,res2)



print("angi test case: "+ str(solOnFile("inp_me")))
print("gio test case: "+ str(solOnFile("inp")))
 