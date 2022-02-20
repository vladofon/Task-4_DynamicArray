#pragma once
#include<string>
#include"List.h"
#include"ArrayList.h"
#include "TableSchema.h"
#include "SchemaParser.h"

using namespace std;

class ArrayFormatter
{
public:
   ArrayFormatter(TableSchema* schema)
   {
      this->schema = schema;
   }

   ArrayFormatter(int cols)
   {
      // If constructor empty define default schema
      this->schema = new TableSchema();
      initDefaultSchema(cols);
   }

   string format(int** numbers, int cols, int rows)
   {
      List<List<string>*>* columns;

      columns = parseNumbers(numbers, cols, rows);

      for (int j = 0; j <= cols; j++)
      {
         schema->fillColumn(0, j, columns->get(j));
      }

      SchemaParser* parser = new SchemaParser(*schema);
      return parser->parseSchema();
   }

private:
   TableSchema* schema;

   void initDefaultSchema(int cols)
   {
      schema->createRow("Grid");
      for (int i = 0; i <= cols; i++)
      {
         schema->getRow(0).createColumn(" ");
      }
   }

   List<List<string>*>* parseNumbers(int** numbers, int cols, int rows)
   {
      List<List<string>*>* stringNumbers = new ArrayList<List<string>*>();

      List<string>* firstColumn = new ArrayList<string>();
      for (int j = 0; j < rows; j++)
      {
         firstColumn->add(" ");
      }

      stringNumbers->add(firstColumn);

      for (long i = 0; i < rows; i++)
      {
         for (long j = 1; j <= cols; j++)
         {
            if (stringNumbers->getSize() < (j + 1))
            {
               stringNumbers->add(new ArrayList<string>);
            }

            stringNumbers->get(j)->add(to_string(numbers[i][j - 1]));
         }
      }

      return stringNumbers;
   }
};