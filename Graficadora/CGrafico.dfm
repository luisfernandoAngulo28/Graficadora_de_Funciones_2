object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 369
  ClientWidth = 675
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 8
    Width = 32
    Height = 16
    Caption = 'F(x)='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 352
    Top = 176
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Button1: TButton
    Left = 32
    Top = 17
    Width = 89
    Height = 25
    Caption = 'Crear'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 48
    Width = 89
    Height = 25
    Caption = 'poner termino'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 312
    Top = 300
    Width = 89
    Height = 25
    Caption = 'Graficar  '
    TabOrder = 2
    OnClick = Button5Click
  end
  object Button3: TButton
    Left = 24
    Top = 288
    Width = 89
    Height = 41
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 119
    Top = 296
    Width = 98
    Height = 33
    Caption = 'Button4'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button6: TButton
    Left = 32
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 119
    Top = 196
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'Edit1'
  end
end
