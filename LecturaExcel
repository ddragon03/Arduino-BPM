package LecturaExcel;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Date;
import java.util.Iterator;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellType;
import org.apache.poi.ss.usermodel.DateUtil;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class ExcelRead {

	public static void main(String[] args) {

		File archivo = new File("BPM.xlsx");

		try {
			FileInputStream input = new FileInputStream(archivo);
			XSSFWorkbook libro = new XSSFWorkbook(input);
			XSSFSheet hoja = libro.getSheetAt(0);

			Row fila = hoja.getRow(2);

			Iterator<Row> filas = hoja.rowIterator();
			Iterator<Cell> columnas = null;
			Row filaNOW = null;
			Cell columnaNOW = null;

		while(filas.hasNext()) {
				filaNOW=filas.next();
				columnas=filaNOW.cellIterator();
				while(columnas.hasNext()){
					columnaNOW=columnas.next();
					if(columnaNOW.getCellType()== CellType.NUMERIC) {
						valor = columnaNOW.getNumericCellValue();
						System.out.println(valor);
						double valorLeido = valor; // Ejemplo de valor leído del archivo Excel
						AnalizadorBPM procesador = new AnalizadorBPM(valorLeido);
						procesador.procesarValor();
					}
					if(columnaNOW.getCellType()== CellType.NUMERIC && DateUtil.isCellDateFormatted(columnaNOW)) {
						Date fecha = columnaNOW.getDateCellValue();
						System.out.println(fecha );
					}
				}
				input.close();
				libro.close();
			}
		
		} catch (Exception e) {

			e.printStackTrace();
		}


	}

}
