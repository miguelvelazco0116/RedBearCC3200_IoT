// ************************************************************************************************************************
// ************************************************************************************************************************

void createJSON(float data00, char* source00, float data01, char* source01)
{  
  float data2send00, data2send01;  
  
  data2send00 = data00;
  data2send01 = data01;
  aJsonObject *dataJson;

  dataJson = aJson.createObject();
  aJson.addItemToObject(dataJson, source00, aJson.createItem(data2send00));
  aJson.addItemToObject(dataJson, source01, aJson.createItem(data2send01));
   
  char* JSON = aJson.print(dataJson);  
  client.publish(topic_MQTT, JSON);  

  aJson.deleteItem(dataJson);  
  dataJson = aJson.parse(JSON);
  free(JSON);
  JSON = aJson.print(dataJson);
  free(JSON);
  aJson.deleteItem(dataJson);  
  
}
