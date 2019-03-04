from program import *

if __name__ == '__main__':
    app = wx.App()
    frm = HelloFrame(None, title="Crypto", style = wx.DEFAULT_FRAME_STYLE ^ wx.RESIZE_BORDER ^ wx.MAXIMIZE_BOX)
    frm.SetSize(800, 480)
    print("Window created with resolution {} ".format(frm.GetSize()))
    frm.Show()
    app.MainLoop()
