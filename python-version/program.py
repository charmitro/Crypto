# TODO: SET ICON.
import wx
from sha import *
from encrypt import *

class HelloFrame(wx.Frame):
    def __init__(self, *args, **kw):
        super(HelloFrame, self).__init__(*args, **kw)

        """ ICON
        icon = wx.EmptyIcon()
        icon.CopyFromBitmap(wx.Bitmap("icon.ico", wx.BITMAP_TYPE_ANY))
        self.SetIcon(icon)
        """
        pnl = wx.Panel(self)
        pnl.SetBackgroundColour(wx.Colour(65, 65, 182))
        ###KEY###
        st = wx.StaticText(pnl, label="Key:", pos=(2, 10))
        font = st.GetFont()
        font.PointSize = 10
        font = font.Bold()
        st.SetFont(font)
        self.key = 2
        self.keyinput = wx.TextCtrl(pnl,size=(40, 40) ,pos=(30,10), value = str(self.key))
        self.keybtn = wx.Button(pnl, size=(18, 20), pos=(50, 10), style = wx.BORDER_NONE)
        self.keybtn.SetBackgroundColour(wx.BLACK)
        ######
        ###ENCRYPT###
        self.encinput = wx.TextCtrl(pnl, size=(400, 100), pos=(200, 10), value="peos")
        self.encbtn = wx.Button(pnl, label="ENCRYPT", size=(400, 40), pos=(200, 115), style=wx.BORDER_NONE)
        self.encbtn.SetBackgroundColour(wx.BLACK)
        self.encbtn.SetForegroundColour(wx.YELLOW)
        ######
        ###DECRYPT###
        self.decinput = wx.TextCtrl(pnl, size=(400, 100), pos=(200, 160))
        self.decbtn = wx.Button(pnl, label="DECRYPT", size=(400, 40), pos=(200, 265), style= wx.BORDER_NONE)
        self.decbtn.SetBackgroundColour(wx.BLACK)
        self.decbtn.SetForegroundColour(wx.YELLOW)
        ######
        ###SHA256###
        self.shalab = wx.StaticText(pnl, label="SHA256 OF THE NON ENCRYPTED TEXT", pos=(300, 310))
        self.shaout = wx.TextCtrl(pnl,size=(400, 50), pos=(200, 330))
        self.shafont = self.shalab.GetFont()
        self.shafont = font.Bold()
        self.shalab.SetFont(self.shafont)
        ######

        self.makeMenuBar()
        self.encbtn.Bind(wx.EVT_BUTTON, self.OnE)
        self.encbtn.Bind(wx.EVT_BUTTON, self.OnSha)
        self.decbtn.Bind(wx.EVT_BUTTON, self.OnD)
        self.keybtn.Bind(wx.EVT_BUTTON, self.SetKey)
    def makeMenuBar(self):
        fileMenu = wx.Menu()
        fileMenu.AppendSeparator()
        exitItem = fileMenu.Append(wx.ID_EXIT)
        helpMenu = wx.Menu()
        aboutItem = helpMenu.Append(wx.ID_ABOUT)

        menuBar = wx.MenuBar()
        menuBar.Append(fileMenu, "&File")
        menuBar.Append(helpMenu, "&Help")

        self.SetMenuBar(menuBar)
        self.Bind(wx.EVT_MENU, self.OnExit,  exitItem)
        self.Bind(wx.EVT_MENU, self.OnAbout, aboutItem)

    def OnExit(self, event):
        self.Close(True)

    def OnAbout(self, event):
        wx.MessageBox("A encryption/decryption program.\nMade by Charalampos Mitrodimas", "Crypto",  wx.OK|wx.ICON_INFORMATION)

    def OnE(self, event):
        self.decinput.SetValue(encrypt(self.encinput.GetValue(), self.key))
        print("Encrypted {} to {}".format(self.encinput.GetValue(), self.decinput.GetValue()))
        event.Skip()

    def OnSha(self, event):
        self.shaout.SetValue(encrypt_string(self.encinput.GetValue()))
        print("Encrypted {} to {}".format(self.encinput.GetValue(), self.shaout.GetValue()))
        event.Skip()

    def OnD(self, event):
        self.encinput.SetValue(decrypt(self.decinput.GetValue(), self.key))
        print("Decrypted {} to {}".format(self.decinput.GetValue(), self.encinput.GetValue()))
        event.Skip()

    def SetKey(self, event):
        self.key = self.keyinput.GetValue()
        print("Key set to: {}".format(self.keyinput.GetValue()))
        event.Skip()
