/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TableModel;

import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;

/**
 *
 * @author Ui
 */
public class DataTableModel extends AbstractTableModel{
    
    private final ArrayList<String> columnName;
    private Integer[][] data;
    
    public DataTableModel(ArrayList<String> colname, Integer[][] d) {
        columnName = colname;
        data = d;
    }
    
    public void changeData(Integer[][] d) {
        data = d;
        fireTableDataChanged();
    }
    
    @Override
    public String getColumnName(int col) {
        return columnName.get(col);
    }

    @Override
    public int getRowCount() {
        if (data == null) {
            return 0;
        }
        return data.length;
    }

    @Override
    public int getColumnCount() {
        return columnName.size();
    }

    @Override
    public Object getValueAt(int i, int i1) {
        if (i1 == 0) {
            return i + 1;
        }
        return data[i][i1];
    }
    
    @Override
    public void setValueAt(Object val, int row, int col) {
        String tmp = (String)val;
        data[row][col] = Integer.parseInt(tmp);
        fireTableDataChanged();
    }
    
    @Override
    public boolean isCellEditable(int i, int i1) {
        return i1 != 0;
    }
}
